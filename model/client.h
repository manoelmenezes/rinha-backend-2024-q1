#ifndef CLIENT_H
#define CLIENT_H
#include "transaction.h"
#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

struct ExecuteTransactionResponse {
    signed limit = 0;
    signed balance = 0;
};

struct Client {
    unsigned clientId = 0;
    signed limit = 0;
    signed balance = 0;
    void credit(signed value);
    void debit(signed value);
    void executeTransaction(Transaction& transaction, ExecuteTransactionResponse& response);
    json toJson();
    void fromJson(std::string jsonStr);
};

class InsufficientBalanceException: public std::logic_error {
    public:
    InsufficientBalanceException(const signed balance):
            std::logic_error("Insufficient balance"), balance(balance) { }
    const signed balance;
};


#endif
