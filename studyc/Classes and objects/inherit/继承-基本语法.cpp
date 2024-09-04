# include<iostream>
using namespace std;

class Basepage
{
public:
    void Headpage()
    {
        cout << "这是上边栏" << endl;
    }
    void Footpage()
    {
        cout << "这是下边栏" << endl;
    }
    void Left()
    {
        cout << "这是侧边栏" << endl;
    }
};

// 继承基础页面
class CPP: public Basepage
{
public:
    void content()
    {
        cout << "这里是C++学习内容！" << endl;
    }
};

class Java: public Basepage
{
public:
    void content()
    {
        cout << "这里是JAVA学习内容！" << endl;
    }
};

class Python: public Basepage
{
public:
    void content()
    {
        cout << "这里是Python学习内容！" << endl;
    }
};

void test01()
{
    Java ja1;
    CPP cpp;
    Python py;
    ja1.Headpage();
    ja1.content();
    cpp.Headpage();
    cpp.content();
    py.Headpage();
    py.content();
}

int main()
{
    test01();
    system("pause");
    return 0;
}