/*
设计一个英雄的结构体，包括成员姓名、年龄、性别；创建结构体数组，数组中存放5名英雄。
通过冒泡排序算法，将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果
*/
#include <iostream>
#include<string>
using namespace std;

// 创建英雄结构体
struct Hero
{
    string name;
    int age;
    string sex;
};

// 定义冒泡排序
void Bubblesort(struct Hero heros[], int lens)
{
    for (int i = 0; i < lens-1; i++)
    {
        for (int j = 0 ; j< lens-i-1; j++)
        {
            if (heros[j].age > heros[j+1].age)
            {
                struct Hero tump = heros[j];
                heros[j] = heros[j+1];
                heros[j+1] = tump;
            }
        }
    }
}


// 定义打印输出函数
void printfHero(struct Hero heros[], int lens)
{
    for (int i = 0; i<lens; i++)
    {
        cout << heros[i].name << "\t" << heros[i].age << "\t" << heros[i].sex << endl;
    }
}

// 主函数
int main(void)
{
    struct Hero heros[5] = 
    {
        {"刘备",23,"男"},
        {"关羽",22,"男"},
        {"张飞",20,"男"},
        {"赵云",21,"男"},
        {"貂蝉",19,"女"},
    };
    int lens = sizeof(heros) / sizeof(heros[0]);
    //对英雄进行年龄排序
    Bubblesort(heros,lens);
    //输出对应内容
    printfHero(heros, lens);
    system("pause");
    return 0;
}
