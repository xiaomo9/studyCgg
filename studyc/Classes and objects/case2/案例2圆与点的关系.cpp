# include <iostream>
using namespace std;
# include "point.h"

// 定义点类
// class Point
// {
//     public:

//         void setX(int x)
//         {
//             m_x = x;
//         }


//         int getX()
//         {
//             return m_x;
//         }
//         void sety(int y)
//         {
//             m_y = y;
//         }

//         int getY()
//         {
//             return m_y;
//         }

//     private:
//         int m_x;
//         int m_y;
// };

// 定义圆类
class Circle
{
    private:
        int radius;
        Point po;
    public:
        void setRadius(int r)
        {
            radius = r;
        }
        int getradius()
        {
            return radius;
        }
        void setCent(Point p)
        {
            po = p;
        }
        Point getCent()
        {
            return po;
        }

};


void IsinCircle(Circle &c, Point &p)
{
    int dis = (p.getX() - c.getCent().getX()) * (p.getX() - c.getCent().getX())
                + (p.getY() - c.getCent().getY()) * (p.getY() - c.getCent().getY());
    int r2 = c.getradius() * c.getradius();

    cout << "dis=" << dis << "  r2 = " << r2 <<endl;
    cout << "p.getx = " << p.getX() << "  p.gety= " << p.getY() << endl;
    cout << "c.getx = " << c.getCent().getX() << "  c.gety= " << c.getCent().getY() << endl;
    if (dis > r2)
    {
        cout << "点在圆外" << endl;
    }
    else if (dis == r2)
    {
        /* code */
        cout << "点在圆上" << endl;
    }

    else
    {
        cout << "点在圆内" << endl;
    }
    
}

int main()
{
    Circle circle;
    Point p1;
    Point cents;
    circle.setRadius(10);
    cents.setX(10);
    cents.sety(0);
    circle.setCent(cents);
    p1.setX(10);
    p1.sety(9);
    IsinCircle(circle,p1);
    system("pause");
    return 0;
}