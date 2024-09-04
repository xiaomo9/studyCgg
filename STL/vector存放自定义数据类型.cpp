#include<iostream>
#include<vector>
using namespace std;
#include<string>

class Person
{
public:
    //���캯��
    Person(string name, int age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    string m_name;
    int m_age;    
};

// �洢�Զ�������
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

    // ����vector�������
    for(vector<Person>::iterator it = v.begin(); it!=v.end(); it++)
    {
        cout<< it->m_name << ":" << it->m_age << endl;
        // �ڶ��ַ�����
        cout << (*it).m_name << ":" << (*it).m_age << endl;
    }

}

//�洢�Զ�������ָ��
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

    // ����
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