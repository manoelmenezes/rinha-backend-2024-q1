#include "client.h"
#include "transaction.h"
#include "client_service.h"
#include "client_repository.h"
#include <served/served.hpp>
#include "proto/rinha.pb.h"

using std::cout;
using std::endl;

// int main() {
//     Client client;
//     client.clientId = 1;
//     client.limit = 1000;

//     Transaction transaction;
//     transaction.clientId = 1;
//     transaction.type = 'c';
//     transaction.value = 1000;
//     transaction.description = "Credit 1000 into client 1 account";

//     cout << ">>>> Before Transaction: " << endl;
//     cout << "Client ID: " << client.clientId << ". Limit: " << client.limit << ". Balance: " << client.balance << endl;
    
//     ClientService clientService;
//     clientService.clientRepository.addClient(client);
//     ExecuteTransactionResponse response;
//     clientService.executeTransaction(transaction, response);

//     cout << ">>>> After transaction: " << endl;
//     cout << "Client ID: " << client.clientId << ". Limit: " << client.limit << ". Balance: " << client.balance << endl;
//     cout << "Transaction: " << transaction.description << ". Client ID: " << transaction.clientId << ". Type: " << transaction.type << ". Value: " << transaction.value << endl;
//     cout << "Response new limit: " << response.limit << ". Response new balance: " << response.balance << endl;

//     Client clientAfterTransaction = clientService.clientRepository.getClient(transaction.clientId);
//     cout << ">>>> Client after transaction: " << endl;
//     cout << "Client ID: " << clientAfterTransaction.clientId << ". Limit: " << clientAfterTransaction.limit << ". Balance: " << clientAfterTransaction.balance << endl;

//     cout << "Are client address the same? " << (&clientAfterTransaction == &client) << endl;

// }



int main(int argc, char const* argv[]) {
	// Create a multiplexer for handling requests
	served::multiplexer mux;

    rinha::Balance balance;
    
    // GET /clientes/[id]/extrato
	mux.handle("/clients/{id}/extrato")
		.get([](served::response & res, const served::request & req) {
			res << "User: " << req.params["id"];
		});

    // POST /clientes/[id]/transacoes
    mux.handle("/clients/{id}/transacoes")
        .post([](served::response & res, const served::request & req) {
		if (req.header("Content-Type") != "application/json") {
			served::response::stock_reply(400, res);
			return;
		}
		res << req.url().fragment();
	});

	// Create the server and run with 10 handler threads.
	served::net::server server("127.0.0.1", "8080", mux);
	server.run(10);

	return (EXIT_SUCCESS);
}
