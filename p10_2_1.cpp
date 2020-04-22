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
	Point& operator-(const Point &ref)
	{
		Point rtn;
		rtn.xpos = -ref.xpos;
		rtn.ypos = -ref.ypos;
		return rtn;
	}
	friend Point& operator~(const Point &ref)
};

Point& operator~(const Point &ref)
{
	Point rtn;
	rtn.xpos = ref.ypos;
	rtn.ypos = ref.xpos;
	return rtn;
}