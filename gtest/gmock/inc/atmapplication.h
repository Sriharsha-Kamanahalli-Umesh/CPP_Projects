#include <iostream>
#include "abankserver.h"
class Atmmachine {
  public:
    Atmmachine(BankServer *server);
    bool WithDraw(int account_number, double amount);
    double CheckBalance(int account_number);

  private:
    BankServer *server_;
};