#include <iostream>
#include <cstring>
using namespace std;

class MyfriendInfo
{
private:
	char *name;
	int age;
public:
	MyfriendInfo(const char* str, int num) : age(num)
	{
		name = new char[strlen(str) + 1];
		strcpy(name, str);
	}
	~MyfriendInfo()
	{
		delete []name;
	}
	void ShowMyfriednInfo()
	{
		cout<<"name: "<<name<<endl;
		cout<<"age: "<<age<<endl;
	}
};

class MyfriednDetailInfo : public MyfriendInfo
{
private:
	char *addr;
	char *phone;
public:
	MyfriednDetailInfo(const char* name, int age, const char* address, const char* phonenum) : MyfriendInfo(name, age)
	{
		addr = new char[strlen(address) + 1];
		phone = new char[strlen(phonenum) + 1];
		strcpy(addr, address);
		strcpy(phone, phonenum);
	}
	~MyfriednDetailInfo()
	{
		delete []addr;
		delete []phone;
	}
	void ShowMyfriendDetailInfo()
	{
		ShowMyfriednInfo();
		cout<<"address: "<<addr<<endl;
		cout<<"phone: "<<phone<<endl<<endl;
	}
};

int main()
{
	MyfriendInfo info1("bk", 28);
	MyfriednDetailInfo info2("hi", 28, "superville", "0101111111");
	info1.ShowMyfriednInfo();
	info2.ShowMyfriendDetailInfo();
	return 0;
}