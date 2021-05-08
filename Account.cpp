//
//  Account.cpp
//  Wallet
//
//  Created by rui wang on 4/26/21.
//

#include "Account.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;
 long Account::NextAccountNum=0;
Account::Account(string fname,string lname,float balance=0.0){
    NextAccountNum++;
    accountNum=NextAccountNum;
    this->firstname=fname;
    this->lastname=lname;
    this->balance=balance;
}
void Account::Deposit(float num){
    balance+=num;
}
bool Account::Withdraw(float num){
    if(balance-num<0.0)
        return false;
    balance-=num;
    return true;
}
ofstream & operator<<(ofstream &os,Account &acc){
    os<<acc.accountNum<<endl;
    os<<acc.firstname<<endl;
    os<<acc.lastname<<endl;
    os<<acc.balance<<endl;
    return os;
}
ifstream & operator>>(ifstream &os,Account &acc){
    os>>acc.accountNum;
    os>>acc.firstname;
    os>>acc.lastname;
    os>>acc.balance;
    return os;
}
ostream & operator<<(ostream &os,Account &acc){
    os<<"First Name: "<<acc.firstname<<endl;
    os<<"Last Name: "<<acc.lastname<<endl;
    os<<"Account Num: "<<acc.accountNum<<endl;
    os<<"Balance: "<<acc.balance<<endl;
    return os;
}
