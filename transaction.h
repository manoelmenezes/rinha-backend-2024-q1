#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

struct Transaction {
    unsigned clientId = 0;
    char type = ' ';
    unsigned value = 0;
    std::string description = "";
};

#endif
