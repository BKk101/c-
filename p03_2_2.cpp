#include <iostream>
#include <cstring>

using namespace std;

class Printer
{
private :
    char buf[50];
public :
    void SetString(const char *str);
    void ShowString(void);
};

void Printer::SetString(const char *str)
{
    strcpy(buf, str);
}

void Printer::ShowString(void)
{
    cout<<buf<<endl;
}

int main(void)
{
    Printer pnt;
    pnt.SetString("Hello world!");
    pnt.ShowString();

    pnt.SetString("I love C++");
    pnt.ShowString();
    return 0;
}