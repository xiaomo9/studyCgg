# include<iostream>
using namespace std;

class Animal
{
public:
    int m_int;
};

class Sheep: virtual public Animal
{
public:
    Sheep()
    {
        m_int = 18;
    }
};
class Tuo: virtual public Animal
{
public:
    Tuo()
    {
        m_int = 28;
    }
};
class SheepTuo: public Sheep, public Tuo{};

void test01()
{
    SheepTuo yt1;
    cout << yt1.Tuo::m_int << endl;
    cout << yt1.Sheep::m_int << endl;
    cout << yt1.m_int << endl;
}

int main()
{
    test01();
    system("pause");
    return 0;
}