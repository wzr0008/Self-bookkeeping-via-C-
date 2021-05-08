//
//  Account.h
//  Wallet
//
//  Created by rui wang on 4/26/21.
//

#ifndef Account_h
#define Account_h
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;
class Account{
public:
    long accountNum;
    string firstname;
    string lastname;
    float balance;
    static long NextAccountNum;
    Account(){};
    Account(string fname,string lname,float balance);
    long getAccNo(){return accountNum;}
    float getBalance(){return balance;}
    void Deposit(float amount);
    bool Withdraw(float amount);
    friend ofstream & operator<<(ofstream &os,Account &acc);
    friend ifstream & operator>>(ifstream &os,Account &acc);
    friend ostream & operator<<(ostream &os,Account &acc);
    ~Account(){};
};


#endif /* Account_h */
