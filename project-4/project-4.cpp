#include <iostream>
#include <cstring>
using namespace std;

class BankAccount
{
protected:
    int accountNumber;
    char name[50];
    double balance;

public:
    BankAccount()
    {
        accountNumber = 0;
        strcpy(name,"");
        balance = 0;
    }

    virtual void input()
    {
        cout<<"Enter Account Number: ";
        cin>>accountNumber;
        cin.ignore();

        cout<<"Enter Account Holder Name: ";
        cin.getline(name,50);

        cout<<"Enter Initial Balance: ";
        cin>>balance;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout<<"Amount Deposited Successfully"<<endl;
    }

    virtual void withdraw(double amount)
    {
        if(amount <= balance)
        {
            balance -= amount;
            cout<<"Amount Withdrawn Successfully"<<endl;
        }
        else
        {
            cout<<"Insufficient Balance"<<endl;
        }
    }

    double getBalance()
    {
        return balance;
    }

    virtual void display()
    {
        cout<<"Account Number: "<<accountNumber<<endl;
        cout<<"Account Holder: "<<name<<endl;
        cout<<"Balance: "<<balance<<endl;
    }

    virtual void calculateInterest()
    {
        cout<<"No interest for this account"<<endl;
    }

    int getAccountNumber()
    {
        return accountNumber;
    }
};

class SavingsAccount : public BankAccount
{
    double interestRate;

public:
    void input()
    {
        BankAccount::input();
        cout<<"Enter Interest Rate: ";
        cin>>interestRate;
    }

    void calculateInterest()
    {
        double interest = balance * interestRate / 100;
        cout<<"Interest: "<<interest<<endl;
    }
};

class CheckingAccount : public BankAccount
{
    double overdraftLimit;

public:
    void input()
    {
        BankAccount::input();
        cout<<"Enter Overdraft Limit: ";
        cin>>overdraftLimit;
    }

    void withdraw(double amount)
    {
        if(amount <= balance + overdraftLimit)
        {
            balance -= amount;
            cout<<"Withdraw Successful"<<endl;
        }
        else
        {
            cout<<"Overdraft limit exceeded"<<endl;
        }
    }
};

class FixedDepositAccount : public BankAccount
{
    int term;

public:
    void input()
    {
        BankAccount::input();
        cout<<"Enter Term (months): ";
        cin>>term;
    }

    void calculateInterest()
    {
        double interest = balance * 0.08 * term / 12;
        cout<<"Fixed Deposit Interest: "<<interest<<endl;
    }
};

class Bank
{
    BankAccount* list[100];
    int count;

public:
    Bank()
    {
        count = 0;
    }

    void addAccount(BankAccount* acc)
    {
        list[count++] = acc;
        cout<<"Account Created Successfully"<<endl;
    }

    void displayAccounts()
    {
        for(int i=0;i<count;i++)
        {
            cout<<"\nAccount "<<i+1<<endl;
            list[i]->display();
        }
    }

    BankAccount* search(int accNo)
    {
        for(int i=0;i<count;i++)
        {
            if(list[i]->getAccountNumber()==accNo)
                return list[i];
        }
        return NULL;
    }
};

int main()
{
    Bank bank;
    int choice;

    while(true)
    {
        cout<<"\n1 Create Account";
        cout<<"\n2 Deposit";
        cout<<"\n3 Withdraw";
        cout<<"\n4 Show Accounts";
        cout<<"\n5 Calculate Interest";
        cout<<"\n6 Exit";
        cout<<"\nEnter Choice: ";
        cin>>choice;

        if(choice==1)
        {
            cout<<"\n1 Savings";
            cout<<"\n2 Checking";
            cout<<"\n3 Fixed Deposit";
            cout<<"\nEnter type: ";

            int t;
            cin>>t;

            BankAccount* acc;

            if(t==1) acc = new SavingsAccount();
            else if(t==2) acc = new CheckingAccount();
            else acc = new FixedDepositAccount();

            acc->input();
            bank.addAccount(acc);
        }

        else if(choice==2)
        {
            int accNo;
            double amt;

            cout<<"Enter Account Number: ";
            cin>>accNo;

            BankAccount* acc = bank.search(accNo);

            if(acc)
            {
                cout<<"Enter Amount: ";
                cin>>amt;
                acc->deposit(amt);
            }
            else
            cout<<"Account not found"<<endl;
        }

        else if(choice==3)
        {
            int accNo;
            double amt;

            cout<<"Enter Account Number: ";
            cin>>accNo;

            BankAccount* acc = bank.search(accNo);

            if(acc)
            {
                cout<<"Enter Amount: ";
                cin>>amt;
                acc->withdraw(amt);
            }
            else
            cout<<"Account not found"<<endl;
        }

        else if(choice==4)
        {
            bank.displayAccounts();
        }

        else if(choice==5)
        {
            int accNo;
            cout<<"Enter Account Number: ";
            cin>>accNo;

            BankAccount* acc = bank.search(accNo);

            if(acc)
                acc->calculateInterest();
            else
                cout<<"Account not found"<<endl;
        }

        else if(choice==6)
        {
            break;
        }

        else
        {
            cout<<"Invalid choice"<<endl;
        }
    }

    return 0;
}