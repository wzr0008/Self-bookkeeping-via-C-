//
//  Bank.h
//  Wallet
//
//  Created by rui wang on 4/26/21.
//

#ifndef Bank_h
#define Bank_h
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>
#include "Account.h"
using namespace std;
class Bank:public Account{
private:
    map<long,Account> accounts;
public:
    Bank();
    Account OpenAccount(string fname,string lname,float balance);
    Account BalanceEnquiry(long accountNum);
    Account Deposit(long accountNum,float amount);
    Account Withdraw(long accountNum,float amount);
    void CloseAccount(long accountNum);
    void ShowAllAccount();
    ~Bank();
};
#endif /* Bank_h */
