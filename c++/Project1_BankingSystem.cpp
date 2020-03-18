#include <iostream>
#include <string.h>
#define BUFF_SIZE 100

using namespace std;

typedef struct s_client_info
{
    int id;
    char name[30];
    long long balance;
} t_client_info;

int display_menu(void)
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

void create_account(t_client_info *client_info)
{
    cout<<"[계좌개설]"<<endl;
    cout<<"계좌ID: ";
    cin>>client_info->id;
    cout<<"이 름: ";
    cin>>client_info->name;
    cout<<"입금액: ";
    cin>>client_info->balance;
    cout<<endl;
}

void deposite(t_client_info *client_info)
{
    int id, deposite;

    cout<<"[입  금]"<<endl;
    cout<<"계좌ID: ";
    cin>>id;
    cout<<"입금액: ";
    cin>>deposite;
    for (int i = 0;i < BUFF_SIZE; i++)
    {
        if (client_info[i].id == id)
            client_info[i].balance += deposite; 
    }
    cout<<"입금완료"<<endl;
    cout<<endl;
}

void withdraw(t_client_info *client_info)
{
    int id, withdraw;

    cout<<"[출  금]"<<endl;
    cout<<"계좌ID: ";
    cin>>id;
    cout<<"출금액: ";
    cin>>withdraw;
    for (int i = 0;i < BUFF_SIZE; i++)
    {
        if (client_info[i].id == id)
            client_info[i].balance -= withdraw; 
    }
    cout<<"출금완료"<<endl;
    cout<<endl;
}

void display_all_account(t_client_info *client_info)
{
    for (int i = 0;i < BUFF_SIZE; i++)
    {
        if (client_info[i].id == 0)
            break;
        cout<<"계좌ID: "<<client_info[i].id<<endl;
        cout<<"이 름: "<<client_info[i].name<<endl;
        cout<<"잔 액: "<<client_info[i].balance<<endl;
        cout<<endl;
    }
}

int main()
{
    int menu, i;
    t_client_info client_info[BUFF_SIZE];
    
    memset(client_info, 0, sizeof(t_client_info) * BUFF_SIZE);
    i = 0;
    while (i < BUFF_SIZE)
    {
        menu = display_menu();
        if (menu == 1)
            create_account(&client_info[i++]);
        else if (menu == 2)
            deposite(client_info);
        else if (menu == 3)
            withdraw(client_info);
        else if (menu == 4)
            display_all_account(client_info);
        else if (menu == 5)
            break;
        else
            cout<<"잘못 입력하였습니다. 다시입력하세요."<<endl<<endl;
    }
    cout<<"프로그램 종료"<<endl;   
    return (0);
}