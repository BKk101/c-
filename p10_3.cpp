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
	friend ostream& operator<<(ostream &ref, Point &pt);
	friend istream& operator>>(istream &ref, Point &pt);
};

ostream& operator<<(ostream &ref, Point &pt)
{
	ref<<pt.xpos<<", "<<pt.ypos<<endl;
	return ref;
}

istream& operator>>(istream &ref, Point &pt)
{
	int xpos, ypos;
	ref>>xpos>>ypos;
	Point pos(xpos, ypos);
	pt = pos;
	return ref; 
}

int main()
{
	Point pos1;
	cin>>pos1;
	cout<<pos1;
	return 0;
}
