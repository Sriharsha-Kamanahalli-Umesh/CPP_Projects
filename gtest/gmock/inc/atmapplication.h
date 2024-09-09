#include <iostream>
#include "abankserver.h"

namespace bankserverapplication {
class Atmmachine {
  public:
    Atmmachine(BankServer *server);
    bool WithDraw(int account_number, double amount);
    double CheckBalance(int account_number);

  private:
    BankServer *server_;
};

} // namespace bankserverapplication