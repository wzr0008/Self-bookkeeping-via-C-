//
//  main.cpp
//  Wallet
//
//  Created by rui wang on 4/26/21.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>
#include "Account.h"
#include "Bank.h"
int main(int argc, const char * argv[]) {
    Bank b;
    Account acc;
    int choice;
    string fname,lname;
    long accountNum;
    float balance;
    float amount;
    cout<<"****Banking System***"<<endl;
    do{
        cout<<"\n\t Select one option below ";
        cout<<"\n\t 1 Open an Account";
        cout<<"\n\t 2 Balance Enquiry";
        cout<<"\n\t 3 Deposit";
        cout<<"\n\t 4 Withdrawal";
        cout<<"\n\t 5 Close an account";
        cout<<"\n\t 6 Show all accounts";
        cout<<"\n\t 7 Quit";
        cin>>choice;
        switch(choice)
        {
            case 1:{
                cout<<"Enter First Name: ";
                cin>>fname;
                cout<<"Enter Last Name: ";
                cin>>lname;
                cout<<"Enter initil Balance: ";
                cin>>balance;
                acc=b.OpenAccount(fname,lname,balance);
                cout<<endl<<"Congradulation Account is Created"<<endl;
                cout<<acc;
                break;
            }
            case 2:{
                cout<<"Enter Account Number: ";
                cin>>accountNum;
                acc=b.BalanceEnquiry(accountNum);
                cout<<endl<<"Your Account Details"<<endl;
                cout<<acc;
                break;
            }
            case 3:{
                cout<<"Enter Account Number: ";
                cin>>accountNum;
                cout<<"Enter Balance: ";
                cin>>amount;
                acc=b.Deposit(accountNum,amount);
                cout<<endl<<"Amount is Deposited"<<endl;
                cout<<acc;
                break;
            }
            case 4:{
                cout<<"Enter Account Number: ";
                cin>>accountNum;
                cout<<"Enter Balance: ";
                cin>>amount;
                acc=b.Withdraw(accountNum,amount);
                cout<<endl<<"Amount Withdrawn"<<endl;
                cout<<acc;
                break;
            }
            case 5:{
                cout<<"Enter Account Number: ";
                cin>>accountNum;
                b.CloseAccount(accountNum);
                cout<<endl<<"Account is Closed"<<endl;
                cout<<acc;
                break;
            }
            case 6:{
                b.ShowAllAccount();
                break;
            }
            case 7:
                break;
            default:
                cout<<"\nEnter correct choice";
                exit(0);
        }
    }
    while(choice!=7);
    return 0;
}
