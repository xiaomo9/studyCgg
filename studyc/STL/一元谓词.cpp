#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>

// 仿函数（返回bool类型的叫谓词）
class greaterfive
{
public:
    bool operator()(int a)
    {
        return a > 5;
    }
};


void test01()
{
    vector<int> v;
    for(int i = 0; i<10; i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator it = find_if(v.begin(),v.end(),greaterfive());// 匿名仿函数

    if(it != v.end())
    {
        cout << "存在大于5的数:" << (*it) << endl;
    }
    else
    {
        cout << "不存在大于5的数" << endl;
    }

    }


int main()
{
    test01();
    system("pause");
}