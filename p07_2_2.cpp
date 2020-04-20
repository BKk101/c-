#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
	char* title;
	char* isbn;
	int price;
public:
	Book(const char* name, const char* num, int bprice) : price(bprice)
	{
		title = new char[strlen(name) + 1];
		isbn = new char[strlen(num) + 1];
		strcpy(title, name);
		strcpy(isbn, num);
	}
	~Book()
	{
		delete []title;
		delete []isbn;
	}
	void ShowBookInfo()
	{
		cout<<"title: "<<title<<endl<<"ISBN: "<<isbn<<endl<<"price: "<<price<<endl;
	}
};

class EBook : public Book
{
private:
	char* DRMkey;
public:
	EBook(const char* name, const char* num, int bprice, const char* key) : Book(name, num, bprice)
	{
		DRMkey = new char[strlen(key) + 1];
		strcpy(DRMkey, key);
	}
	~EBook()
	{
		delete []DRMkey;
	}
	void ShowEBookInfo()
	{
		ShowBookInfo();
		cout<<"DRMkey: "<<DRMkey<<endl;
	}
};

int main()
{
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout<<endl;
	EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	return 0;
}