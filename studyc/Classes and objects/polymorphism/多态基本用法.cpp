# include<iostream>
using namespace std;

// 先声明子类与父类，父类有virtual虚函数声明
// 父类指针和引用指向子类对象（可以引用多态）

class Animal
{
public:
    virtual void speek()
    {
        cout << "动物在叫！" << endl;
    }
};

class Cat :public Animal
{
public:
    void speek()
    {
        cout << "小猫在叫！" << endl;
    }
};

void DoSpeek(Animal &animal)// 使用父类的指针
{
    animal.speek();
}

void test01()
{   
    Cat cat01;
    DoSpeek(cat01); // 将子类对象传入父类函数
}

int main()
{   
    test01();
    system("pause");
    return 0;
}

