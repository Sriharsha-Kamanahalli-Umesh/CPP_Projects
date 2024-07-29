#include <iostream>
// BankServer.h
class BankServer {
public:
    virtual ~BankServer() = default;
    virtual void Connect() = 0;
    virtual void Disconnect() = 0;
    virtual void Credit(int account_number, double amount) = 0;
    virtual void Debit(int account_number, double amount) = 0;
    virtual double GetBalance(int account_number) const = 0;
};
