#include "atmapplication.h"

namespace bankserverapplication {

/**
 * @brief Constructor.
 * @param server Pointer to a BankServer object.
 */
Atmmachine::Atmmachine(BankServer *server) : server_(server) {}

/**
 * @brief Withdraw an amount from an account.
 * @param account_number Account number to withdraw from.
 * @param amount Amount to withdraw.
 * @return True if the withdrawal was successful, false otherwise.
 */
bool Atmmachine::WithDraw(int account_number, double amount) {
  bool draw_amount = false;
  server_->Connect();
  
  double account_balance = server_->GetBalance(account_number);

  if (account_balance >= amount) {
    draw_amount = true;
  }
  server_->Disconnect();
  return draw_amount;
}

/**
 * @brief Check the balance of an account.
 * @param account_number Account number to check balance.
 * @return Balance of the account.
 */
double Atmmachine::CheckBalance(int account_number) {
  return server_->GetBalance(account_number);
}

} // namespace bankserverapplication