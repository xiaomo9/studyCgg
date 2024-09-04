# include<iostream>
using namespace std;

// 定义自己的整形类
class MyInt
{
    friend ostream& operator<<(ostream &cout, MyInt int1);
public:
    MyInt()
    {
        this->m_int = 10;
    }

    // 定义重载前置++运算符
    MyInt& operator++()
    {
        m_int ++;
        return *this;
    }

    // 定义重载后置++运算符
    MyInt operator++(int) // 固定语法int做占位符的作用，这样就表示后置运算
    {
        MyInt temp = *this;
        m_int ++;
        return temp;
    }

private:
    int m_int;
};


// 定义重载 << 运算符
ostream& operator<<(ostream &cout, MyInt int1)
{
    cout << int1.m_int;
    return cout;
}

// 测试前置++运算符
void test1()
{
    MyInt int1;
    cout << ++int1 << endl;
    cout << int1 << endl;
}

// 测试后置++运算符
void test2()
{
    MyInt int2;
    cout << int2++ << endl;
    cout << int2 << endl;
}

int main()
{
    test1();
    test2();
    system("pause");
    return 0;
}