#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// �º���
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

    // ʹ��transformʱһ��Ҫ�ȸ�Ŀ�����������ڴ�ռ�
    v2.resize(v.size());
    transform(v.begin(),v.end(),v2.begin(),Transform());
    for_each(v2.begin(),v2.end(),print());
}


int main()
{
    test01();

    system("pause");
}