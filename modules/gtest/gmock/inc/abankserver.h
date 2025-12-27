#include "bankserver.h"

namespace bankserverapplication {

/**
 * @brief Abstract bank server implementation.
 */
class AbankServer : public BankServer {
public:
    /**
     * @brief Constructor.
     */
    AbankServer();

    /**
     * @brief Connect to the bank server.
     */
    void Connect() override;

    /**
     * @brief Disconnect from the bank server.
     */
    void Disconnect() override;

    /**
     * @brief Credit an amount to an account.
     * @param account_number Account number to credit.
     * @param amount Amount to credit.
     */
    void Credit(int account_number, double amount) override;

    /**
     * @brief Debit an amount from an account.
     * @param account_number Account number to debit.
     * @param amount Amount to debit.
     */
    void Debit(int account_number, double amount) override;

    /**
     * @brief Get the balance of an account.
     * @param account_number Account number to check balance.
     * @return Balance of the account.
     */
    double GetBalance(int account_number) const override;

private:
    double balance_; ///< Balance of the account
};

} // namespace bankserverapplication