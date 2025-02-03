#include <iostream>
#include "abankserver.h"

namespace bankserverapplication {

/**
 * @brief Class representing an ATM machine.
 */
class Atmmachine {
public:
    /**
     * @brief Constructor.
     * @param server Pointer to a BankServer object.
     */
    Atmmachine(BankServer *server);

    /**
     * @brief Withdraw an amount from an account.
     * @param account_number Account number to withdraw from.
     * @param amount Amount to withdraw.
     * @return True if the withdrawal was successful, false otherwise.
     */
    bool WithDraw(int account_number, double amount);

    /**
     * @brief Check the balance of an account.
     * @param account_number Account number to check balance.
     * @return Balance of the account.
     */
    double CheckBalance(int account_number);

private:
    BankServer *server_; ///< Pointer to the bank server
};

} // namespace bankserverapplication