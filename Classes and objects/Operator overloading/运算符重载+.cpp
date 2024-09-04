#include<iostream>
using namespace std;

class Person
{
public:
    string m_name;
    int m_age;
    int m_menoy;

    Person()
    {
        this->m_age = 10;
        this->m_menoy = 9000;
    }

    //成员函数实现运算符重载
    Person operator+ (Person &p)
    {
        Person temp;
        temp.m_age = p.m_age + m_age;
        temp.m_menoy = p.m_menoy + m_menoy;

        return temp;
    }
private:
};

//全局函数实现运算符重载
Person operator+ (Person &p1 , Person &p2)
{
    Person temp;
    temp.m_age = p1.m_age + p2.m_age;
    temp.m_menoy = p1.m_menoy + p2.m_menoy;
    return temp;
}


void test()
{
    Person p1;
    Person p2;
    Person p3 = p1 + p2;

    cout << "age = " << p3.m_age << endl;
    cout << "menoy = " << p3.m_menoy << endl;
}

int main()
{
    test();

    system("pause");
    return 0;
}