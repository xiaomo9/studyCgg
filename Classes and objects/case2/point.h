# pragma once
# include <iostream>
using namespace std;

class Point
{
    public:

        void setX(int x);

        int getX();

        void sety(int y);

        int getY();

    private:
        int m_x;
        int m_y;
};
