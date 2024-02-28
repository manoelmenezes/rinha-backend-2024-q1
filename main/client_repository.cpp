#include "client_repository.h"
#include "client.h"
#include "transaction.h"
#include <vector>

using std::vector;

void ClientRepository::executeTransaction(Transaction & transaction)
{
    this->transactions.push_back(transaction);
}

void ClientRepository::updateClient(const Client &client)
{
    Client& client_tmp = this->getClient(client.clientId);
    client_tmp.balance = client.balance;
    client_tmp.limit = client.limit;
}

vector<Transaction> ClientRepository::getTransactions(const unsigned clientId)
{
    vector<Transaction> result;
    for (unsigned i = 0; i < this->transactions.size(); i++) 
    {
        if (this->transactions[i].clientId == clientId) 
        {
            result.push_back(this->transactions[i]);
        }
    }
    return result;
}

void ClientRepository::addClient(Client &client)
{
    this->clients.push_back(client);
}

Client& ClientRepository::getClient(unsigned clientId)
{
    for (unsigned i = 0; i < this->clients.size(); i++) 
    {
        if (this->clients[i].clientId == clientId)
        {
            return this->clients[i];
        }
    }
    throw new ClientNotFoundException(clientId);
}
