# include<iostream>
using namespace std;

class Calculator
{
public:
    int m_num1;
    int m_num2;

    virtual int getresult() = 0; // 构造纯虚函数
};
// 定义加法计算器
class AddCalculator :public Calculator
{
public:
    int getresult()
    {
        return m_num1 + m_num2;
    }
};
// 定义减法计算器
class DelCalculator :public Calculator
{
public:
    int getresult()
    {
        return m_num1 - m_num2;
    }
};
//定义乘法计算器
class MulCalculator :public Calculator
{
public:
    int getresult()
    {
        return m_num1 * m_num2;
    }
};

void test01()
{
    //测试加法计算器
    Calculator *ca2 = new AddCalculator;
    ca2 -> m_num1 = 10;
    ca2 -> m_num2 = 20;
    cout << ca2 -> getresult() << endl;
    delete ca2;

    //测试减法计算器
    ca2 = new DelCalculator;
    ca2 -> m_num1 = 10;
    ca2 -> m_num2 = 20;
    cout << ca2 -> getresult() << endl;
    delete ca2;

    //测试乘法计算器
    ca2 = new MulCalculator;
    ca2 -> m_num1 = 10;
    ca2 -> m_num2 = 20;
    cout << ca2 -> getresult() << endl;
    delete ca2;

}

int main()
{
    test01();
    system("pause");
    return 0;
}