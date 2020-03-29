#include <iostream>
#include <cstring>
using namespace std;


namespace COMP_POS
{
    enum
    {
        CLERK, SENIOR, ASSIST, MANAGER
    };
}

class NameCard
{
private:
    char *name;
    char *company_name;
    char *telephone;
    int position;
public:
    NameCard(const char *str1, const char *str2, const char *number, int pos): position(pos)
    {
        int len = strlen(str1) + 1;
        name = new char[len];
        strcpy(name, str1);
        len = strlen(str2) + 1;
        company_name = new char[len];
        strcpy(company_name, str2);
        len = strlen(number) + 1;
        telephone = new char[len];
        strcpy(telephone, number);
    }
    void ShowNameCardInfo(void)
    {
        cout<<"이름: "<<name<<endl;
        cout<<"회사: "<<company_name<<endl;
        cout<<"전화번호: "<<telephone<<endl;
        cout<<"직급: "<<position<<endl<<endl;

    }
};

int main()
{
    NameCard manClerk("Lee", "ABCeng", "010-1111-2222", COMP_POS::CLERK);
    NameCard manSenior("Lee", "ABCeng", "010-1111-2222", COMP_POS::SENIOR);
    NameCard manAssist("Lee", "ABCeng", "010-1111-2222", COMP_POS::ASSIST);
    manClerk.ShowNameCardInfo();
    manSenior.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();
    return 0;
}