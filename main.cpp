#include "client.h"
#include "transaction.h"
#include "client_service.h"
#include "client_repository.h"

using std::cout;
using std::endl;

int main() {
    cout << "Started" << endl;
    Client client;
    client.clientId = 1;
    client.limit = 1000;
    cout << "Client created:" << client.clientId << endl;

    Transaction transaction;
    transaction.clientId = 1;
    transaction.type = 'c';
    transaction.value = 1000;
    transaction.description = "Credit 1000 into client 1 account";
    cout << "Transaction created:" << transaction.description << endl;

    // cout << "Client id: " << client.clientId << endl;
    // cout << "Transaction value: " << transaction.value << endl;

    ClientService clientService;
    clientService.clientRepository.addClient(client);
    // clientService.clientRepository = ClientRepository{};
    clientService.executeTransaction(transaction, client);

    cout << "Client ID: " << client.clientId << endl;

}
