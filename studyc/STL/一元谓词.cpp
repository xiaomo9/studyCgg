#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>

// �º���������bool���͵Ľ�ν�ʣ�
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
    vector<int>::iterator it = find_if(v.begin(),v.end(),greaterfive());// �����º���

    if(it != v.end())
    {
        cout << "���ڴ���5����:" << (*it) << endl;
    }
    else
    {
        cout << "�����ڴ���5����" << endl;
    }

    }


int main()
{
    test01();
    system("pause");
}