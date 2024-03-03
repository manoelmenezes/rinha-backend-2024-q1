#include "model/client.h"
#include "model/transaction.h"
#include "model/client_service.h"
#include "model/client_repository.h"
#include <served/served.hpp>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

using std::cout;
using std::endl;

int main(int argc, char const* argv[]) {
	ClientService clientService;
	// Create a multiplexer for handling requests
	served::multiplexer mux;

    // GET /clientes/[id]/extrato
	mux.handle("/clientes/{id}/extrato")
		.get([](served::response & res, const served::request & req) {
			res << "User: " << req.params["id"];
		});

    // POST /clientes/[id]/transacoes
    mux.handle("/clientes/{id}/transacoes")
        .post([](served::response & res, const served::request & req) {
		if (req.header("Content-Type") != "application/json") {
			served::response::stock_reply(400, res);
			return;
		}
		res << req.url().fragment();
	});

	// POST /clientes
    mux.handle("/clientes")
        .post([&clientService](served::response & res, const served::request & req) {
			if (req.header("Content-Type") != "application/json") {
				served::response::stock_reply(400, res);
				return;
			}
			Client client;
			client.fromJson(req.body());
			clientService.clientRepository.addClient(client);
			served::response::stock_reply(200, res);
		})
		.get([&clientService](served::response & res, const served::request & req) {
			json clients = json::array();
			for (int i = 0; i < clientService.clientRepository.clients.size(); i++) {
				json client =  clientService.clientRepository.clients[i].toJson();				
				clients.push_back(client);
			}
			res << clients.dump();
		});

	// Create the server and run with 10 handler threads.
	served::net::server server("127.0.0.1", "8080", mux);
	server.run(10);

	return (EXIT_SUCCESS);
}
