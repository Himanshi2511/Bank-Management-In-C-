#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;

class bank
{
    char name[100] , add[100] , o;
    int bal;
    long int acc_number;
    long long int no;
    public:
    void open_acc();
    void deposit_money();
    void withdraw_money();
    void display_info();
    void modify_account();
    int search(int);
};
/*OPENING THE ACCOUNT*/
void bank :: open_acc()
{
    cout<<"Enter your full name: ";
    cin.ignore();
    cin.getline(name,100);
    cout<<"Enter your address: ";
    cin.ignore();
    cin.getline(add,100);
    cout<<"What type of account - Savings(s) or Current(c): ";
    cin>>o;
    cout<<"Enter The account Number: ";
    cin>>acc_number;
    cout<<"Enter your phone number: ";
    cin>>no;
    cout<<"Enter amount to be deposited: ";
    cin>>bal;
    if(bal<2000)
    {
        cout<<"Amount should be atleast 2000";
    }
    else{
    cout<<"Your account is created \n";
    }
    cout<<"\n";
}

/*DEPOSITING MONEY IN ACCOUNT*/
void bank :: deposit_money()
{
    int a;
    cout<<"Enter the amount you want to deposit: ";
    cin>>a;
    bal = bal + a;
    cout<<"Total balance in your account: ";
    cout<<bal;
    cout<<"\n";
    cout<<"\n";
}

/*WITHDRAWING MONEY FROM ACCOUNT*/
void bank :: withdraw_money()
{
    
    float amt;
    cout<<"Enter the amount you want to withdraw: ";
    cin>>amt;

    if(bal<amt)
    {
        cout<<"Not sufficient balance";
    }
    else{
    cout<<"Total balance in your account: ";
    bal = bal - amt;
    cout<<bal;
    }
    cout<<"\n";
    cout<<"\n";
}

/*DISPLAYING ALL ACCOUNT INFORMATION*/
void bank :: display_info()
{
    cout<<"Your name: \t"<<name;
    cout<<"\n";
    cout<<"Your address: \t"<<add;
    cout<<"\n";
    cout<<"Type of account : \t"<<o;
    cout<<"\n";
    cout<<"Your account number: \t"<<acc_number;
    cout<<"\n";
    cout<<"Your phone number: \t"<<no;
    cout<<"\n";
    cout<<"Balance in your account: \t"<<bal;
    cout<<"\n";
    cout<<"\n"; 
}

/*MODIFYING YOUR ACCOUNT INFORMATION*/
void bank :: modify_account()
{
        cout<<"Your account number: "<<acc_number;
        cout<<"\n";
        cout<<"Modify Account Holder Name: ";
        cin.ignore();
        cin.getline(name,100);
        cout<<"\n";
        cout<<"Modify Type of Account: ";
        cin>>o;
}

/*SEARCHING BY ACCOUNT NUMBER*/
int bank :: search(int a)
{
    if (acc_number == a) {
        display_info();
        return (1);
    }
    return (0);
}

int main()
{
    int ch , x , a , i , found =0;
    bank obj[2];
    
    do
    {
cout<<"1. Open Account \n";
cout<<"2. Deposit Money \n";
cout<<"3. Withdraw Money \n";
cout<<"4. Display  All Account Information \n";
cout<<"5. Modify Account Information \n";
cout<<"6. Searching By Account Number \n";
cout<<"7. Exit \n";
cout<<"Select one of the option from above. \n";
cin>>ch;
switch(ch)
{
    case 1: "1. Open Account \n";
    for (i = 0; i <= 2; i++) {
                obj[i].open_acc();
            }
    break;

    case 2: "2. Deposit Money \n";
    cout << "Account Number To Deposit Amount: \t";
            cin >> a;
            for (i = 0; i <= 2; i++) {
                found = obj[i].search(a);
                if (found) {
                    obj[i].deposit_money();
                    break;
                }
            }
            if (!found)
                cout << "Record Not Found" << endl;
    break;

    case 3: "3. Withdraw Money \n";
     cout << "Account Number To Withdraw Amount? ";
            cin >> a;
            for (i = 0; i <= 2; i++) {
                found = obj[i].search(a);
                if (found) {
                    obj[i].withdraw_money();
                    break;
                }
            }
            if (!found)
                cout << "Record Not Found" << endl;
    break;

    case 4: "4. Display Account Information \n";
    for (i = 0; i <= 2; i++) {
                obj[i].display_info();
            }
    break;

    case 5: "5. Modify Account Information \n";
    cin >> a;
            for (i = 0; i <= 2; i++) {
                found = obj[i].search(a);
                if (found) {
                    obj[i].modify_account();
                    break;
                }
            }
            if (!found)
                cout << "Record Not Found" << endl;
    break;

    case 6: "Searching By Account Number \n";
    cin >> a;
            for (i = 0; i <= 2; i++) {
                found = obj[i].search(a);
                if (found) {
                    obj[i].display_info();
                    break;
                }
            }
            if (!found)
                cout << "Record Not Found" << endl;
    break;
    case 7:
    if(ch == 7)
    {
        exit(1);
    }

    default:
    cout<<"Wrong Input \n";
}

cout<<"If you want to select next option then press 'y'\n ";
cout<<"If you  want to exit then press 'n' \n ";
x = getch();
if (x == 'n' || x == 'N')
exit(0);
    }

while(x == 'y' || x=='Y');

getch();
return 0;

}