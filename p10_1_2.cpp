#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y)
	{}
	void ShowPosition() const
	{
		cout<<xpos<<", "<<ypos<<endl;
	}
	Point& operator+=(const Point &ref1);
	Point& operator-=(const Point &ref1);
};

Point& Point::operator+=(const Point &ref1)
{
	xpos += ref1.xpos;
	ypos += ref1.ypos;
	return *this;
}

Point& Point::operator-=(const Point &ref1)
{
	xpos -= ref1.xpos;
	ypos -= ref1.ypos;
	return *this;
}

int main()
{
	Point pos1(3,4);
	Point pos2(3,4);
	pos1 += pos2;
	pos1.ShowPosition();
	pos1 -= pos2;
	pos1.ShowPosition();
	return 0;
}