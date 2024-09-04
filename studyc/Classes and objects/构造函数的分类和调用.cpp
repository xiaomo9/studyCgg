# include<iostream>
using namespace std;


//对象的初始化和清理
//利用构造函数进行初始化
//利用析构函数进行清理、

class Person
{
private:
    /* data */
public:
    // 无参构造函数
    Person()
    {
        cout << "无参构造函数的调用" << endl;
    }
    // 有参构造函数
    Person(int a1)
    {
        a = a1;
        cout << "有参构造函数调用" << endl;
    }

    // 拷贝构造函数
    Person(const Person &p)
    {
        a = p.a;
        cout << "拷贝构造函数的调用" << endl;
    }

    // 析构函数
    ~Person()
    {
        cout << "类已清除！" << endl;
    }

    int a;
};

void test()
{
    Person p1;

}



int main()
{
    // 无参调用
    Person p1;
    // 有参调用
    Person p2(10);
    // 拷贝调用
    Person p3(p1);
    system("pause");
}
