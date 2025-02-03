#include "abankserver.h"

namespace bankserverapplication {

/**
 * @brief Constructor.
 */
AbankServer::AbankServer() : balance_(0.0) {}

/**
 * @brief Connect to the bank server.
 */
void AbankServer::Connect() {
  std::cout << "Bank Server Connected" << "\n";
}

/**
 * @brief Disconnect from the bank server.
 */
void AbankServer::Disconnect() {
  std::cout << "Bank Server Disconnected" << "\n";
}

/**
 * @brief Credit an amount to an account.
 * @param account_number Account number to credit.
 * @param amount Amount to credit.
 */
void AbankServer::Credit(int account_number, double amount) {
  (void)account_number;
  balance_ += amount;
}

/**
 * @brief Debit an amount from an account.
 * @param account_number Account number to debit.
 * @param amount Amount to debit.
 */
void AbankServer::Debit(int account_number, double amount) {
  (void)account_number;
  balance_ -= amount;
}

/**
 * @brief Get the balance of an account.
 * @param account_number Account number to check balance.
 * @return Balance of the account.
 */
double AbankServer::GetBalance(int account_number) const {
  return balance_;
}

} // namespace bankserverapplication