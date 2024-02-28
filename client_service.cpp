#include "client_service.h"
#include "client.h"
#include "transaction.h"
#include "client_repository.h"

void ClientService::executeTransaction(Transaction &transaction, Client &client)
{
   Client& client_tmp = this->clientRepository.getClient(transaction.clientId);
   client_tmp.executeTransaction(transaction, client);
   this->clientRepository.updateClient(client_tmp);
   this->clientRepository.executeTransaction(transaction);
}

vector<Transaction> ClientService::getTransactions(unsigned clientId)
{
    return this->clientRepository.getTransactions(clientId);
}

