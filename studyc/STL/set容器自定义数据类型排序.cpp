#include<iostream>
#include<set>
using namespace std;

class Person
{
public:
    string m_name;
    int m_age;

    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }
};

// �Զ���������������
class MyCompare
{
public:
    bool operator()(const Person&p1, const Person&p2) const
    {
        return p1.m_age < p2.m_age;
    }
};

void printset(set<Person,MyCompare> &s)
{
    for(set<Person,MyCompare>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << "������" << (*it).m_name << "  ���䣺" << (*it).m_age << endl;
    }
}

void test01()
{
    set<Person,MyCompare> s;
    Person p1("��˹", 56);
    Person p2("����", 35);
    Person p3("Ӯ��", 20);
    Person p4("�Ը�", 89);
    
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);
    printset(s);
}


int main()
{
    test01();
    system("pause");
}