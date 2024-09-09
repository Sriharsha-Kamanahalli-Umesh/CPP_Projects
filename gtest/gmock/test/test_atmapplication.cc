#include <iostream>
#include "atmapplication.h"

#include "gtest/gtest.h"
// #include "gmock/gmock.h"

namespace bankserverapplication {

TEST(Atmmachine, TestingAtmmachine) {
  AbankServer server;
  Atmmachine atmachine(&server);
  bool withdraw_result = atmachine.WithDraw(1234, 1000);
  EXPECT_FALSE(withdraw_result);
  
  double amount = atmachine.CheckBalance(1234);
  EXPECT_EQ(amount, 0.0);
}

// using ::testing::Return;
// class MockBankServer : public BankServer {
//   public:
//     MOCK_METHOD(void, Connect, (), (override));
//     MOCK_METHOD(void, Disconnect, (), (override));
//     MOCK_METHOD(void, Credit, (int account_number, double amount), (override));
//     MOCK_METHOD(void, Debit, (int account_number, double amount), (override));
//     MOCK_METHOD(double, GetBalance, (int account_number), (const, override));
// };

// TEST(Atmmachine, TestingAtmmachineUsingMock) {
//   MockBankServer mock_server;

//   EXPECT_CALL(mock_server, GetBalance(1234))
//               .Times(2)
//               .WillRepeatedly(Return(1000));

//   Atmmachine atmachine(&mock_server);
//   auto withdraw_result = atmachine.WithDraw(1234, 1000);
//   EXPECT_TRUE(withdraw_result);
//   double amount = atmachine.CheckBalance(1234);
//   EXPECT_EQ(amount, 1000);
// }


} // namespace bankserverapplication