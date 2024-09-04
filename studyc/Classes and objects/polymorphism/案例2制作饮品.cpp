# include<iostream>
using namespace std;

// 定义制作饮品基类
class AbstractDrink
{
public:
    // 煮水
    virtual void Boil() = 0; // 纯虚函数
    // 冲泡
    virtual void Brew() = 0; // 
    // 倒入杯中
    virtual void PourIncup() = 0;
    // 加入辅料
    virtual void Addsomething() = 0;

    // 开始制作饮品
    void domake()
    {
        Boil();
        Brew();
        PourIncup();
        Addsomething();
    }
};

// 定义咖啡子类
class coffee :public AbstractDrink
{
    void Boil()
    {
        cout << "-----制作咖啡-----" <<endl;
        cout << "开始煮水" << endl;
    }

    void Brew()
    {
        cout << "冲泡咖啡" << endl;
    }

    void PourIncup()
    {
        cout << "将咖啡倒入杯中" << endl;
    }

    void Addsomething()
    {
        cout << "加入糖和牛奶" << endl;
    }
};
// 定义茶子类
class tea :public AbstractDrink
{
    void Boil()
    {
        cout << "-----制作茶-----" <<endl;
        cout << "开始煮水" << endl;
    }

    void Brew()
    {
        cout << "冲泡茶叶" << endl;
    }

    void PourIncup()
    {
        cout << "将茶水倒入杯中" << endl;
    }

    void Addsomething()
    {
        cout << "加入枸杞" << endl;
    }
};

void DoDrink(AbstractDrink *abs)
{
    abs->domake();
}

void test01()
{
    DoDrink(new coffee); //父类指针指向子类对象
    DoDrink(new tea);
}

int main()
{
    test01();
    system("pause");
    return 0;
}

