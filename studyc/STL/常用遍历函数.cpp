#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 仿函数
class print
{
public:
    void operator()(int a)
    {
        cout << a << endl;
    }
};

class Transform
{
public:
    int operator()(int a)
    {
        return a + 100;
    }
};

void test01()
{
    vector<int> v;
    for(int i = 0; i< 10; i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(),v.end(),print());
    vector<int> v2;

    // 使用transform时一定要先给目标容器开辟内存空间
    v2.resize(v.size());
    transform(v.begin(),v.end(),v2.begin(),Transform());
    for_each(v2.begin(),v2.end(),print());
}


int main()
{
    test01();

    system("pause");
}