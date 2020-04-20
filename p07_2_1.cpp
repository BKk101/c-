#include <iostream>
using namespace std;

class Rectangle
{
private:
	int height;
	int width;
public:
	Rectangle(int a, int b) : height(a), width(b)
	{}
	void ShowAreaInfo()
	{
		cout<<"area: "<<height * width<<endl;
	}
};

class Square : public Rectangle
{
public:
	Square(int a) : Rectangle(a, a)
	{}
};

int main()
{
	Rectangle rec(4,3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}