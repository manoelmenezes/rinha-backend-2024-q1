#ifndef CLIENT_REPOSITORY_H
#define CLIENT_REPOSITORY_H

#include "client.h"
#include "transaction.h"
#include <vector>

using std::vector;

struct ClientRepository {
    void executeTransaction(Transaction &transaction);
    void updateClient(const Client &client);
    void addClient(Client &client);
    vector<Transaction> getTransactions(const unsigned clientId);
    Client& getClient(unsigned clientId);
    vector<Client> clients;
    vector<Transaction> transactions;
};

// class ClientNotFoundException: public std::logic_error {
//     public:
//     ClientNotFoundException(const unsigned clientId):
//             std::logic_error("Client not found"), clientId(clientId) { }
//     const unsigned clientId;
// };

#endif
