#include<iostream>
using namespace std;

class Person
{
public:
    Person(string name1, int age1)
    {
        this->age = age1;
        this->name = name1;
    }

    // 重载关系运算符==
    bool operator==(Person &p2)
    {
        if(name == p2.name && age == p2.age)
        {
            return true;
        }    
        else
        {
            return false;
        }
    }

    //重载关系运算符！=
    bool operator!=(Person p2)
    {
        if(name == p2.name && age == p2.age)
        {
            return false;
        }    
        else
        {
            return true;
        }
    } 

private:
    string name;
    int age;
};


void test01()
{
    Person p1("xiaomo", 20);
    Person p2("xiaomo", 20);
    Person p3("mobai", 23);

    if (p1 == p2)
    {
        cout << "两个人是同一个人" << endl;
    }
    else
    {
        cout << "两个人不是同一个人" << endl;
    }

    if (p1 != p2)
    {
        cout << "两个人不是同一个人" << endl;
    }
    else
    {
        cout << "两个人是同一个人" << endl;
    }
}

int main()
{
    test01();
    system("pause");
    return 0;
}