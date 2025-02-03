#include <iostream>

namespace bankserverapplication {

/**
 * @brief Interface for a bank server.
 */
class BankServer {
public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~BankServer() = default;

    /**
     * @brief Connect to the bank server.
     */
    virtual void Connect() = 0;

    /**
     * @brief Disconnect from the bank server.
     */
    virtual void Disconnect() = 0;

    /**
     * @brief Credit an amount to an account.
     * @param account_number Account number to credit.
     * @param amount Amount to credit.
     */
    virtual void Credit(int account_number, double amount) = 0;

    /**
     * @brief Debit an amount from an account.
     * @param account_number Account number to debit.
     * @param amount Amount to debit.
     */
    virtual void Debit(int account_number, double amount) = 0;

    /**
     * @brief Get the balance of an account.
     * @param account_number Account number to check balance.
     * @return Balance of the account.
     */
    virtual double GetBalance(int account_number) const = 0;
};

} // namespace bankserverapplication
