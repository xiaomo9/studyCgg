# include <iostream>
using namespace std;

class Person
{
private:
    /* data */
public:
    int age;
    int *p;

    Person(int ages, int height)
    {
        age = ages;
        // 开辟新的堆内存空间
        p = new int(height);
        cout << "有参构造函数" << endl;
    }

    // 拷贝构造函数
    Person(const Person &p1)
    {
        age = p1.age;
        //  深拷贝，开辟新的内存空间
        // p = p1.p;
        p = new int(*p1.p);
    }

    ~Person()
    {
        cout << "析构函数已运行" << endl;
        if (p != NULL)
        {
            delete p;
            p  = NULL;
        }
    }
};

void test()
{
    Person p1(10,160);
    Person p2(p1);
}

int main()
{
    test();
    system("pause");
    return 0;
}