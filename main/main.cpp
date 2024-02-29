#include "client.h"
#include "transaction.h"
#include "client_service.h"
#include "client_repository.h"

using std::cout;
using std::endl;

int main() {
    Client client;
    client.clientId = 1;
    client.limit = 1000;

    Transaction transaction;
    transaction.clientId = 1;
    transaction.type = 'c';
    transaction.value = 1000;
    transaction.description = "Credit 1000 into client 1 account";

    cout << ">>>> Before Transaction: " << endl;
    cout << "Client ID: " << client.clientId << ". Limit: " << client.limit << ". Balance: " << client.balance << endl;
    
    ClientService clientService;
    clientService.clientRepository.addClient(client);
    ExecuteTransactionResponse response;
    clientService.executeTransaction(transaction, response);

    cout << ">>>> After transaction: " << endl;
    cout << "Client ID: " << client.clientId << ". Limit: " << client.limit << ". Balance: " << client.balance << endl;
    cout << "Transaction: " << transaction.description << ". Client ID: " << transaction.clientId << ". Type: " << transaction.type << ". Value: " << transaction.value << endl;
    cout << "Response new limit: " << response.limit << ". Response new balance: " << response.balance << endl;

    Client clientAfterTransaction = clientService.clientRepository.getClient(transaction.clientId);
    cout << ">>>> Client after transaction: " << endl;
    cout << "Client ID: " << clientAfterTransaction.clientId << ". Limit: " << clientAfterTransaction.limit << ". Balance: " << clientAfterTransaction.balance << endl;

    cout << "Are client address the same? " << (&clientAfterTransaction == &client) << endl;

}
