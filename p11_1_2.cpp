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
    Book(const Book& ref): price(ref.price)
    {
        title = new char[strlen(ref.title) + 1];
        isbn = new char[strlen(ref.isbn) + 1];
        strcpy(title, ref.title);
        strcpy(isbn, ref.isbn);
    }
    Book& operator=(const Book& ref)
    {
        price = ref.price;
        delete []title;
        delete []isbn;
        title = new char[strlen(ref.title) + 1];
        isbn = new char[strlen(ref.isbn) + 1];
        strcpy(title, ref.title);
        strcpy(isbn, ref.isbn);
        return *this;   
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
    EBook(const EBook& ref): Book(ref)
    {
        DRMkey = new char[strlen(ref.DRMkey) + 1];
        strcpy(DRMkey, ref.DRMkey);
    }
    EBook& operator=(const EBook& ref)
    {
        Book::operator=(ref);
        delete []DRMkey;
        DRMkey=new char[strlen(ref.DRMkey) + 1];
        strcpy(DRMkey,ref.DRMkey);
        return *this;
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