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

    // ���ع�ϵ�����==
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

    //���ع�ϵ�������=
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
        cout << "��������ͬһ����" << endl;
    }
    else
    {
        cout << "�����˲���ͬһ����" << endl;
    }

    if (p1 != p2)
    {
        cout << "�����˲���ͬһ����" << endl;
    }
    else
    {
        cout << "��������ͬһ����" << endl;
    }
}

int main()
{
    test01();
    system("pause");
    return 0;
}