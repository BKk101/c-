#include <stdlib.h>

typedef struct __Point
{
    int xpos;
    int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2)
{
    Point *rtn = new Point;

    rtn->xpos = p1.xpos + p2.xpos;
    rtn->ypos = p1.ypos + p2.ypos;
    return (*rtn);
}

int main()
{
    Point *p1 = new Point;
    p1->xpos = 1;
    p1->ypos = 1;

    Point *p2 = new Point;
    p2->xpos = 10;
    p2->ypos = 10;

    Point ref = PntAdder(*p1, *p2);
    return 0;
}