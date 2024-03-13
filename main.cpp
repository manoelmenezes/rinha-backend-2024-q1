#include "model/client.h"
#include "model/transaction.h"
#include "model/client_service.h"
#include "model/client_repository.h"
#include <nlohmann/json.hpp>
#include <iostream>
#include <pqxx/pqxx>
#include <pistache/endpoint.h>

using namespace Pistache;

using json = nlohmann::json;

using std::cout;
using std::endl;

struct HelloHandler : public Http::Handler {
  HTTP_PROTOTYPE(HelloHandler)
  void onRequest(const Http::Request&, Http::ResponseWriter writer) override {
    writer.send(Http::Code::Ok, "Hello, World!");
  }
};

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
	    // If you need to access the result metadata, not just the actual
            // field values, use the "exec" functions.  Most of them return
            // pqxx::result objects.
            pqxx::result res = tx.exec("SELECT id, bound, balance FROM clients");
            std::cout << "Columns:\n";
            for (pqxx::row_size_type col = 0; col < res.columns(); ++col)
                std::cout << res.column_name(col) << '\n';

            std::cout << "Making changes definite: ";
            tx.commit();
            std::cout << "OK.\n";
        }
        catch (std::exception const &e)
        {
            std::cerr << "ERROR: " << e.what() << '\n';
            return 1;
        }


	ClientService clientService;

	Http::listenAndServe<HelloHandler>(Pistache::Address("*:9080"));
	
	return (EXIT_SUCCESS);
}
