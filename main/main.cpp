//#include "model/client.h"
//#include "model/transaction.h"
//#include "model/client_service.h"
//#include "model/client_repository.h"
#include <nlohmann/json.hpp>
#include <pqxx/pqxx>

using json = nlohmann::json;

using std::cout;
using std::endl;

int main(int argc, char const* argv[]) {
	try
        {
            // Connect to the database.  You can have multiple connections open
            // at the same time, even to the same database.
            pqxx::connection c("host=localhost port=5432 dbname=rinha user=rinha_user password=123456");
            std::cout << "Connected to " << c.dbname() << '\n';

            // Start a transaction.  A connection can only have one transaction
            // open at the same time, but after you finish a transaction, you
            // can start a new one on the same connection.
            pqxx::work tx{c};

            // Query data of two columns, converting them to std::string and
            // int respectively.  Iterate the rows.
            for (auto [id, bound, balance] : tx.query<int, int, int>(
                "SELECT id, bound, balance FROM clients"))
            {
                std::cout << "Client id: " << id << " has limit " << bound << " and balance " << balance << ".\n";
            }

            std::cout << "Making changes definite: ";
            tx.commit();
            std::cout << "OK.\n";
        }
        catch (std::exception const &e)
        {
            std::cerr << "ERROR: " << e.what() << '\n';
            return 1;
        }


//	ClientService clientService;
	// Create a multiplexer for handling requests
//	served::multiplexer mux;

    // GET /clientes/[id]/extrato
//	mux.handle("/clientes/{id}/extrato")
//		.get([](served::response & res, const served::request & req) {
//			res << "User: " << req.params["id"];
//		});

    // POST /clientes/[id]/transacoes
//    mux.handle("/clientes/{id}/transacoes")
//       .post([](served::response & res, const served::request & req) {
//		if (req.header("Content-Type") != "application/json") {
//			served::response::stock_reply(400, res);
//			return;
//		}
//		res << req.url().fragment();
//	});

	// POST /clientes
//    mux.handle("/clientes")
//        .post([&clientService](served::response & res, const served::request & req) {
//			if (req.header("Content-Type") != "application/json") {
//				served::response::stock_reply(400, res);
//				return;
//			}
//			Client client;
//			client.fromJson(req.body());
//			clientService.clientRepository.addClient(client);
//			served::response::stock_reply(200, res);
//		})
//		.get([&clientService](served::response & res, const served::request & req) {
//			json clients = json::array();
//			for (int i = 0; i < clientService.clientRepository.clients.size(); i++) {
//				json client =  clientService.clientRepository.clients[i].toJson();				
//				clients.push_back(client);
//			}
//			res << clients.dump();
//		});

	// Create the server and run with 10 handler threads.
//	served::net::server server("127.0.0.1", "8080", mux);
//	server.run(10);

	return (EXIT_SUCCESS);
}
