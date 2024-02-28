#include "client.h"
#include "transaction.h"

void Client::credit(signed value)
{
    this->balance += value;
}

void Client::debit(signed value)
{
    signed newBalance = this->balance - value;
    if (newBalance < -this->limit) 
    {
        throw new InsufficientBalanceException(newBalance);
    }
    this->balance = newBalance;
}

void Client::executeTransaction(Transaction &transaction, Client &client)
{
    if (transaction.type == 'c') 
    {
        this->credit(transaction.value);
    }
    else
    {
        this->debit(transaction.value);
    }
    client.balance = this->balance;
    client.limit = this->limit;
}
