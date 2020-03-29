#include <iostream>

using namespace std;

class Circle
{
private:
    int xpos, ypos, radius;
public:
    Circle(int x, int y, int r): xpos(x), ypos(y), radius(r)
    {}

    void ShowCircleInfo() const
    {
        cout<<"radius: "<<radius<<endl;
        cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
    }
};

class Ring
{
private:
    Circle inner, outter;
public:
    Ring(int x1, int y1, int r1, int x2, int y2, int r2): inner(x1, y1, r1), outter(x2,y2,r2)
    {}
    
    void ShowRingInfo() const
    {
        cout<<"Inner Circle Info..."<<endl;
        inner.ShowCircleInfo();
        cout<<"Outter Circle Info..."<<endl;
        outter.ShowCircleInfo();
    }
};

int main(void)
{
    Ring ring(1,1,4,2,2,9);
    ring.ShowRingInfo();
    return 0;
}