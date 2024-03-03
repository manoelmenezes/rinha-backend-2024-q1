#ifndef CLIENT_SERVICE_H
#define CLIENT_SERVICE_H

#include "client.h"
#include "client_repository.h"
#include "transaction.h"
#include <vector>

using std::vector;

struct ClientService {
    void executeTransaction(Transaction& transaction, ExecuteTransactionResponse& response);
    vector<Transaction> getTransactions(unsigned clientId);
    ClientRepository clientRepository = ClientRepository {};
};

#endif
