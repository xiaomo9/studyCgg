#include<iostream>
#include<vector>
using namespace std;
#include<string>

class Person
{
public:
    //构造函数
    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    string m_name;
    int m_age;    
};

// 存储自定义数据
void test01()
{
    vector<Person> v;
    Person p1("xiaomo",20);
    Person p2("xiaoli",21);
    Person p3("xiaobai",24);
    Person p4("mobai",25);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    // 遍历vector里的内容
    for(vector<Person>::iterator it = v.begin(); it!=v.end(); it++)
    {
        cout<< it->m_name << ":" << it->m_age << endl;
        // 第二种方法、
        cout << (*it).m_name << ":" << (*it).m_age << endl;
    }

}

//存储自定义数据指针
void test02()
{
    vector<Person*> v;
    Person p1("xiaomo",20);
    Person p2("xiaoli",21);
    Person p3("xiaobai",24);
    Person p4("mobai",25);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);

    // 遍历
    for(vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
    {
        Person * p = (*it);  
        cout << p->m_name << ":" << p->m_age << endl;
    }
}

int main()
{
    // test01();
    test02();
    system("pause");
}