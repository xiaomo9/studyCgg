#include<iostream>
using namespace std;

class Person
{
public:
    int age;

    void func1(int age)
    {
        this -> age = age;// ���β�����������ʱ����ָ��ָ��
    }

    Person& add_age(int age) // ����һ�����������Ҳ���Ǳ��������ܶ�������������ʽ������������ص�ֵ����ô�ͻ��ٴο���һ���ռ䣬�����֮ǰ�ı������в���
    {
        this ->age += age;
        return *this;   // this���ص��ó�Ա�������������ָ�룬���return *this��ô���Ƿ����������
    }
};

void test1()
{
    Person xiaomo;
    xiaomo.age = 10;
    cout << "xiaomo:" << xiaomo.age << endl;
    xiaomo.func1(20);
    cout << "xiaomo:" << xiaomo.age << endl;
}

void test2()
{
    Person xiaoao;
    xiaoao.age = 10;
    cout << "xiaomo:" << xiaoao.age << endl;
    xiaoao.add_age(10);
    cout << "xiaomo:" << xiaoao.age << endl;
    xiaoao.add_age(10).add_age(10).add_age(20);
    cout << "xiaomo:" << xiaoao.age << endl;
}


int main()
{
    test2();
    system("pause");
    return 0;

}