#include<iostream>
using namespace std;

class Person
{
public:
    int age;

    void func1(int age)
    {
        this -> age = age;// 当形参与属性重名时可以指代指定
    }

    Person& add_age(int age) // 返回一个对象的引用也就是别名，才能对这个对象进行链式操作，如果返回的值，那么就会再次开辟一个空间，不会对之前的变量进行操作
    {
        this ->age += age;
        return *this;   // this返回调用成员函数所属对象的指针，如果return *this那么就是返回这个对象
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