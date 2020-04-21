#include <iostream>
#include <cstring>
#define BUFF_SIZE 100

using namespace std;

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
	~Account()
    {
        delete []name;
    }
    Account(const Account *ref): id(ref->id), balance(ref->balance)
    {
        name = new char[strlen(ref->name) + 1];
        strcpy(name, ref->name);
    }

    int GetId(void) const {return id;}
    void deposite(int money){balance += money;}
    void withdraw(int money){balance -= money;}
    void ShowInfo(void) const
    {
        cout<<"계좌ID: "<<id<<endl;
        cout<<"이 름: "<<name<<endl;
        cout<<"잔 액: "<<balance<<endl;
        cout<<endl;
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
    int id, balance;
    char name[30];

    cout<<"[계좌개설]"<<endl;
    cout<<"계좌ID: ";
    cin>>id;
    cout<<"이 름: ";
    cin>>name;
    cout<<"입금액: ";
    cin>>balance;
    cout<<endl;

    arr[accnum++] = new Account(id, name, balance);
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