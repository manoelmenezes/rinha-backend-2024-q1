#include "client_service.h"
#include <iostream>

using std::cout;

void ClientService::executeTransaction(Transaction &transaction, Client &client)
{
   Client client_tmp = this->clientRepository.getClient(transaction.clientId);
   client_tmp.executeTransaction(transaction, client);
   this->clientRepository.updateClient(client_tmp);
   this->clientRepository.executeTransaction(transaction);
}

vector<Transaction&> ClientService::getTransactions(unsigned clientId)
{
    return std::move(this->clientRepository.getTransactions(clientId));
}

