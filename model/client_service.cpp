#include "client_service.h"
#include "client.h"
#include "transaction.h"
#include "client_repository.h"

using std::cout;
using std::endl;

void ClientService::executeTransaction(Transaction &transaction, ExecuteTransactionResponse &response)
{
   Client& client_tmp = this->clientRepository.getClient(transaction.clientId);
   client_tmp.executeTransaction(transaction, response);
   this->clientRepository.updateClient(client_tmp);
   this->clientRepository.executeTransaction(transaction);
}

vector<Transaction> ClientService::getTransactions(unsigned clientId)
{
    return this->clientRepository.getTransactions(clientId);
}

