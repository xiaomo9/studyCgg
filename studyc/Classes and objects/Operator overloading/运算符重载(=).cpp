#include<iostream>
using namespace std;

class Person
{
friend void test1();
public:
    Person(int age) // 构造函数
    {
        m_age = new int(age); // 开辟堆区新内存
    }

    ~Person() //析构函数,释放堆区
    {
        if (m_age != NULL)
        {
            delete m_age;
            m_age = NULL;
        }
    }

    // 重载运算符=,深拷贝
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
    
    p3 = p2 = p1; // 用深拷贝代替浅拷贝，浅拷贝不能释放堆区内容
    cout << *p3.m_age << endl;
}


int main()
{
    test1();
    system("pause");
    return 0;
}