#include "bankserver.h"

namespace bankserverapplication {

class AbankServer : public BankServer{
  public:
    AbankServer();
    void Connect() override;
    void Disconnect() override;
    void Credit(int account_number, double amount) override;
    void Debit(int account_number, double amount) override;
    double GetBalance(int account_number) const override;
  private:
    double balance_;

};

} // namespace bankserverapplication