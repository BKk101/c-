#include <iostream>
#include <cstring>
#define BUFF_SIZE 100

using namespace std;

enum 
{
	A = 7,
	B = 4,
	C = 2
};

class Account
{
private:
	int id;
    char *name;
    long long balance;
public:
    Account(int id_num, char *str, long long money): id(id_num), balance(money)
    {
		int len = strlen(str) + 1;
        name = new char[len];
        strcpy(name, str);
	}
	virtual ~Account()
    {
        delete []name;
    }
    Account(const Account *ref): id(ref->id), balance(ref->balance)
    {
        name = new char[strlen(ref->name) + 1];
        strcpy(name, ref->name);
    }

    int GetId(void) const {return id;}
    virtual void deposite(int money){balance += money;}
	virtual int GetInterest(int money) = 0;
    void withdraw(int money){balance -= money;}
    void ShowInfo(void) const
    {
        cout<<"계좌ID: "<<id<<endl;
        cout<<"이 름: "<<name<<endl;
        cout<<"잔 액: "<<balance<<endl;
        cout<<endl;
    }
};

class NormalAccount : public Account
{
private:
	int interest;
public:
	NormalAccount(int id_num, char *str, long long money, int rate)
		: Account(id_num, str, money), interest(rate)
	{}
	int GetInterest(int money)
	{
		return money * interest / 100;
	}
	void deposite(int money)
	{
		Account::deposite(money + GetInterest(money));
	}
};

class HighCreditAccount : public NormalAccount
{
private:
	int credit;
public:
	HighCreditAccount(int id_num, char *str, long long money, int rate, int crdit)
		: NormalAccount(id_num, str, money, rate), credit(crdit)
	{}
	int GetInterest(int money)
	{
		return NormalAccount::GetInterest(money) + money * credit / 100;
	}
	void deposite(int money)
	{
		Account::deposite(money + GetInterest(money));
	}
};

class AccountHandler
{
private:
    Account* arr[BUFF_SIZE];
	int accnum;
public:
	AccountHandler() : accnum(0)
	{}
	int display_menu(void);
	void create_account();
	void deposite();
	void withdraw();
	void display_all_account();
};

int AccountHandler::display_menu(void)
{
    int menu;

    cout<<"-----Menu------"<<endl;
    cout<<"1. 계좌개설"<<endl;
    cout<<"2. 입 금"<<endl;
    cout<<"3. 출 금"<<endl;
    cout<<"4. 계좌정보 전체 출력"<<endl;
    cout<<"5. 프로그램 종료"<<endl;
    cout<<"선택: ";
    cin>>menu;
    cout<<endl;
    return (menu);
}

void AccountHandler::create_account()
{
    int id, balance, interest, type, credit;
    char name[30];

	cout<<"[계좌종류선택]"<<endl;
	cout<<"1.보통예금계좌 "<<"2.신용신뢰계좌"<<endl;
	cout<<"선택: ";
	cin>>type;
	if (type == 1) {
		cout<<"[보통예금계좌 개설]"<<endl;
    	cout<<"계좌ID: "; cin>>id;
    	cout<<"이 름: "; cin>>name;
    	cout<<"입금액: "; cin>>balance;
		cout<<"이자율: "; cin>>interest;
    	cout<<endl;
		arr[accnum++] = new NormalAccount(id, name, balance, interest);
	}
	else {
		cout<<"[신용신뢰계좌 개설]"<<endl;
    	cout<<"계좌ID: "; cin>>id;
    	cout<<"이 름: "; cin>>name;
    	cout<<"입금액: "; cin>>balance;
		cout<<"이자율: "; cin>>interest;
		cout<<"신용등급(1toA, 2toB, 3toC): "; cin>>credit;
    	cout<<endl;
		if (credit == 1)
			arr[accnum++] = new HighCreditAccount(id, name, balance, interest, A);
		else if (credit == 2)
			arr[accnum++] = new HighCreditAccount(id, name, balance, interest, B);
		else if (credit == 3)
			arr[accnum++] = new HighCreditAccount(id, name, balance, interest, C);
	}	
}

void AccountHandler::deposite()
{
    int id, deposite;

    cout<<"[입  금]"<<endl;
    cout<<"계좌ID: ";
    cin>>id;
    cout<<"입금액: ";
    cin>>deposite;
    for (int i = 0;i < accnum; i++)
    {
        if (arr[i]->GetId() == id)
        {
            arr[i]->deposite(deposite);
            break ;
        }
    }
    cout<<"입금완료"<<endl;
    cout<<endl;
}

void AccountHandler::withdraw()
{
    int id, withdraw;

    cout<<"[출  금]"<<endl;
    cout<<"계좌ID: ";
    cin>>id;
    cout<<"출금액: ";
    cin>>withdraw;
    for (int i = 0;i < accnum; i++)
    {
        if (arr[i]->GetId() == id)
        {
            arr[i]->withdraw(withdraw);
            break;
        }
    }
    cout<<"출금완료"<<endl;
    cout<<endl;
}

void AccountHandler::display_all_account()
{
    for (int i = 0;i < accnum; i++)
    {
        arr[i]->ShowInfo();
    }
}

int main()
{
    int menu, i = 0;

	AccountHandler handler;
    while (1)
    {
        menu = handler.display_menu();
        if (menu == 1)
            handler.create_account();
        else if (menu == 2)
            handler.deposite();
        else if (menu == 3)
            handler.withdraw();
        else if (menu == 4)
            handler.display_all_account();
        else if (menu == 5)
            break;
        else
            cout<<"잘못 입력하였습니다. 다시입력하세요."<<endl<<endl;
    }
    cout<<"프로그램 종료"<<endl;   
    return (0);
}