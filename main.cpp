

//Daniel Pepin Project for csci 272
//"Guardian Bank" needs a program to manage it saving accounts. You are to write that program using classes.
// To store the information pertaining to each saving account, define a class named SavAcct using your own names for the data fields and member functions.
// The information you need to store are:
//(1) Account-owners name (a string)
// (2) Account number (a string)
// (3) Current balance (float)
// (4) Annual interest rate (float type; make this a static data field)
#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include "Date.h"
class bank{
private:
    string Name ;
    string Accnumber;
    float bal;
    Date e1;
    constexpr static float interest = 0.035;

public:
    bank SavAccount(){
        Name = "";
        Accnumber = "";
        bal = 0;
        e1.setDate(0,0,0);

    }
    bank SavAccount(string a, string b, float c, Date d){
        Name  = a;
        Accnumber = b;
        bal = c;
        e1.copyDate(d);

    }
  ~bank(){

    }



void getinfo(fstream &instream){//get all of the info
;
    string firstline;   //gets rid of the head of the file
    getline(instream,firstline);
    int m, d ,y;
    instream>>Name>>Accnumber>>bal>>m>>d>>y;
   e1.setDate(m,d,y);

    }
    string getName(){
        return Name;
    }
    float getBal(){
        return bal;
    }
    string getAcc(){
        return Accnumber;
    }
    void prninfo(){
        cout<<Name<<"\t"<<Accnumber<<"\t"<<bal<<"\t";
        e1.displayDate();
        cout<<endl;
  }
void intmonthy(){//will calculate interest
      float calc = bal*interest;
      bal+=calc;
  }
  int findacc(bank a[],int size, string s) {
        int i;



            for ( i = 0; i < size; i++) {
                if(a[i].getAcc() == s){
                    return i;

            }

        }
      if (i == size){
          return -1;
      }



    }

};

int main() {



    bank SavAccount[50];//dont use this just make a normal object and save into arrays
    int i = 0,x=0, sent = 0;
    string search;
    fstream instream("account.txt",ios::in);

    while (!instream.eof()) {
        SavAccount[i].getinfo(instream);
        i++;
    }
    for (int k = 0; k < i-1; ++k) {
        SavAccount[k].intmonthy();
    }
        cout<<"All of the accounts have been credited 3.5% interest"<<endl;

while(sent != -1) {
    cout << "Enter an account number to search for a balance" << endl;
    cin >> search;
    int m = SavAccount[i].findacc(SavAccount, i, search);
    if (m >= 0) {
        SavAccount[m].prninfo();
    } else if (m == -1)
        cout << "account not found"<<endl;
    cout<<"enter 0 to look for another account or -1 to stop: "<<endl;
    cin>>sent;
}




}