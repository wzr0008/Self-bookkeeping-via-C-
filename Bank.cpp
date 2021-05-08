//
//  Bank.cpp
//  Wallet
//
//  Created by rui wang on 4/26/21.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>
#include "Account.h"
#include "Bank.h"
Bank::Bank(){
    Account account;
    ifstream infile;
    infile.open("Bank.data");
    if(!infile){
        cout<<"Error in Opening! File Not Found!!"<<endl;
        return;
    }
    while(!infile.eof()){
        infile>>account;
        accounts.insert(pair<long,Account>(account.getAccNo(),account));
    }
    infile.close();
}
Account Bank::OpenAccount(string fname,string lname,float balance){
    ofstream outfile;
    Account account(fname,lname,balance);
    accounts.insert(pair<long,Account>(account.getAccNo(),account));
    outfile.open("Bank.data",ios::trunc);
    map<long,Account>::iterator itr;
    for(itr=accounts.begin();itr!=accounts.end();itr++){
        outfile<<itr->second;
    }
    outfile.close();
    return account;
}
Account Bank::BalanceEnquiry(long accountNum){
    map<long,Account>::iterator itr=accounts.find(accountNum);
    return itr->second;
}
Account Bank::Deposit(long accountNum,float amount){
    map<long,Account>::iterator itr=accounts.find(accountNum);
    itr->second.Deposit(amount);
    return itr->second;
}
Account Bank::Withdraw(long accountNum,float amount){
    map<long,Account>::iterator itr=accounts.find(accountNum);
    itr->second.Withdraw(amount);
    return itr->second;
}
void Bank::CloseAccount(long num){
    map<long,Account>::iterator itr=accounts.find(num);
    cout<<"Account Deleted"<<itr->second;
    accounts.erase(num);
}
void Bank::ShowAllAccount(){
    map<long,Account>::iterator itr;
    for(itr=accounts.begin();itr!=accounts.end();itr++)
    cout<<"Account "<<itr->first<<endl<<itr->second<<endl;
}
Bank::~Bank(){
    ofstream outfile;
    outfile.open("Bank.data",ios::trunc);
    map<long,Account>::iterator itr;
    for(itr=accounts.begin();itr!=accounts.end();itr++)
    outfile<<itr->second;
    outfile.close();
}
