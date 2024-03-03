#include "client.h"
#include "transaction.h"
#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

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

json Client::toJson()
{
    json client = json::object();
    client["clientId"] = this->clientId;
    client["limit"] = this->limit;
    client["balance"] = this->balance;

    return client;
}

void Client::fromJson(std::string jsonStr)
{
    // TODO(Manoel): add exception handling
    auto jsonObj = json::parse(jsonStr);
    this->clientId = jsonObj["clientId"];
    this->limit = jsonObj["limit"];
    this->balance = jsonObj["balance"];
}
