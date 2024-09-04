/*类外函数或类访问某个类的私有域*/
# include<iostream>
using namespace std;

class Person
{
    //告诉Person类你的好友goodgay来了，他可以访问你的所有内容
    friend void goodgay(Person &p1);

public:
    string Living_room;

    // 构造函数初始化类属性
    Person()
    {
        Living_room = "客厅";
        room = "卧室";
    }

    void print1()
    {
        cout << " 这里是公共区域客厅" << endl;
    }

private:
    string room;

    void print2()
    {
        cout << "这里是私有区域卧室" << endl;
    }
};

void goodgay(Person &p1)
{
    cout << "这里是公共区域：" << p1.Living_room << endl;
    cout << "这里是私有区域：" << p1.room << endl;
}

void test()
{
    Person p1;
    goodgay(p1);
}


int main()
{
    test();

    system("pause");
    return 0;
}