# include<iostream>
using namespace std;

/*
所有的对象共享同一个静态成员
静态成员变量类内声明，类外初始化
静态成员函数只能访问静态成员变量
*/


class Person
{   
    // 静态成员变量：类内声明，类外初始化
public:
    static int jingtai;
     int a = 10; 

    // 静态成员函数
    static void func1()
    {
        jingtai = 10;
        // a = 100; // 静态成员函数只能访问静态成员变量
        cout << "静态成员函数的调用" << endl;
    }


};

//静态成员变量初始化
int Person::jingtai = 100;

void test()
{
    Person p1;
    cout << "访问静态成员变量" << endl;
    cout << "p1 = " << p1.jingtai << endl;
    p1.func1();
    cout << "第二种访问方式" << endl;
    cout << "p1 = " <<Person::jingtai << endl;

    

}

int main() 
{
    test();
    system("pause");
    return 0;
}

