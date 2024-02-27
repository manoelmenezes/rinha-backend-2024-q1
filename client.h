#ifndef CLIENT_H
#define CLIENT_H
#include "transaction.h"

struct Client {
    unsigned clientId = 0;
    unsigned limit = 0;
    signed balance = 0;
    void credit(unsigned value);
    void debit(unsigned value);
    void executeTransaction(Transaction& transaction, Client& client);
};

class InsufficientBalanceException: public std::logic_error {
    public:
    InsufficientBalanceException(const signed balance):
            std::logic_error("Insufficient balance"), balance(balance) { }
    const signed balance;
};


#endif
