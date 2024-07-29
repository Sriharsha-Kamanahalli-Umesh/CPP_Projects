#include "atmapplication.h"

Atmmachine::Atmmachine(BankServer *server) : server_(server) {}

bool Atmmachine::WithDraw(int account_number, double amount) {
  bool draw_amount=false;
  server_->Connect();
  
  double account_balance = server_->GetBalance(account_number);

  if(account_balance >= amount){
    draw_amount = true;
  }
  server_->Disconnect();
  return draw_amount;

}

double Atmmachine::CheckBalance(int account_number) {
  return server_->GetBalance(account_number);
}
