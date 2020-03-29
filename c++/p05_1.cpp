#include <iostream>
#include <cstring>
using namespace std;


namespace COMP_POS
{
    enum
    {
        CLERK = 1, SENIOR, ASSIST, MANAGER
    };

    void show_position(int pos)
    {
        if (pos == 1)
            cout<<"사원"<<endl;
        else if (pos == 2)
            cout<<"대리"<<endl;
        else if (pos == 3)
            cout<<"과장"<<endl;
        else if (pos == 4)
            cout<<"부장"<<endl;
    }
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
    NameCard(const NameCard *ref): position(ref->position)
    {
        name = new char[strlen(ref->name) + 1];
        strcpy(name, ref->name);
        company_name = new char[strlen(ref->company_name) + 1];
        strcpy(name, ref->company_name);
        telephone = new char[strlen(ref->telephone) + 1];
        strcpy(name, ref->telephone);
    }
    void ShowNameCardInfo(void)
    {
        cout<<"이름: "<<name<<endl;
        cout<<"회사: "<<company_name<<endl;
        cout<<"전화번호: "<<telephone<<endl;
        cout<<"직급: "; COMP_POS::show_position(position);
        cout<<endl;
    }
    ~NameCard()
    {
        delete []name;
        delete []company_name;
        delete []telephone;
    }
};

int main()
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard copy1 = manClerk;
    NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard copy2 = manSenior;
    copy1.ShowNameCardInfo();
    copy2.ShowNameCardInfo();
    return 0;
}