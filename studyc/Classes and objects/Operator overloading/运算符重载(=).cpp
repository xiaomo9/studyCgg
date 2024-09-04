#include<iostream>
using namespace std;

class Person
{
friend void test1();
public:
    Person(int age) // ���캯��
    {
        m_age = new int(age); // ���ٶ������ڴ�
    }

    ~Person() //��������,�ͷŶ���
    {
        if (m_age != NULL)
        {
            delete m_age;
            m_age = NULL;
        }
    }

    // ���������=,���
    Person& operator=(Person &p1)
    {
        m_age = new int(*p1.m_age);
        return *this;
    }


private:
    int *m_age;
};


void test1()
{
    Person p1(10);
    Person p2(20);
    Person p3(30);
    
    p3 = p2 = p1; // ���������ǳ������ǳ���������ͷŶ�������
    cout << *p3.m_age << endl;
}


int main()
{
    test1();
    system("pause");
    return 0;
}