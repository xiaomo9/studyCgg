# include<iostream>
using namespace std;

const double PI = 3.14;

// 创建圆类
class Circle
{
    // 私有属性
    private:
    // 公共属性
    public:
    double radius;

    double calaulate()
    {
        return 2*PI*radius;
    }
};


// 定义学生类

class Student
{
    //定义类属性
    public:
    string name;
    string ID;
    //定义类方法
    void setname(string name1)
    {
        name = name1;
    }

    void setID(string ID1)
    {
        ID  = ID1;
    }

    void printinfo()
    {
        cout << "姓名： " << name << "   ID:" << ID << endl;
    }
};


int main()
{
    //实例化 学生类

    Student xiaomo;
    xiaomo.setname("chenadsasao");
    xiaomo.setID("120224");

    xiaomo.printinfo();

    system("pause"); 
    return 0;
}