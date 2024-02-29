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

void Client::executeTransaction(Transaction &transaction, ExecuteTransactionResponse &response)
{
    if (transaction.type == 'c') 
    {
        this->credit(transaction.value);
    }
    else
    {
        this->debit(transaction.value);
    }
    response.balance = this->balance;
    response.limit = this->limit;
}
