#include "abankserver.h"

AbankServer::AbankServer() : balance_(0.0) {}

void AbankServer::Connect() {
  std::cout<<"Bank Server Connected" <<"\n";
}

void AbankServer::Disconnect() {
  std::cout<<"Bank Server Disconnected" <<"\n";
}

void AbankServer::Credit(int account_number, double amount) {
  (void)account_number;
  balance_+=amount;
}

void AbankServer::Debit(int account_number, double amount) {
  (void)account_number;
  balance_-=amount;
}

double AbankServer::GetBalance(int account_number) const {
  return balance_;
}
