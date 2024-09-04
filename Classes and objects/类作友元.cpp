# include<iostream>
using namespace std;

//首先定义一个类，用于后续的友元
class Budding;
class Goodgay
{
public:
    void visit();
    Goodgay();
    Budding * budding;
};


class Budding
{
friend class Goodgay;
public:
    string sittingroom;

    Budding();


private:
    string bedroom;
};

// 在类外定义类的构造函数
Budding::Budding()
{
    this->bedroom = "卧室";
    this->sittingroom = "客厅";
}

Goodgay::Goodgay()
{
    budding = new Budding;
}

void Goodgay::visit()
{
    cout << "这里是公共区域：" << budding->sittingroom << endl;
    cout << "这里是私有区域：" << budding->bedroom << endl;
}


void test()
{
    Goodgay g1;
    g1.visit();

}

int main()
{
    test();

    system("pause");
    return 0;
}