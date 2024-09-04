# include <iostream>
# include <string>
using namespace std;

// 结构体就是自定义数据类型，
// 自定义数据类型，就是一些类型集合组合而成的数据类型

// 定义一个结构体
struct Student

{
    string name;
    int age;
    float score;
};

int main()
{
    Student s1; //实例化结构体
    // 实例化具体结构体属性
    s1.name = "张三";
    s1.age = 18;
    s1.score = 100;

    cout << s1.name << endl;
    cout << s1.age << endl;
    cout << s1.score << endl;

    system("pause");
    return 0;
}