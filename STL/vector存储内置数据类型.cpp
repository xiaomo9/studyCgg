# include<iostream>
using namespace std;
# include<vector>
# include<algorithm> //标准算法头文件

void printfint(int a)
{
    cout << a << endl;
}

void test01()
{
    // 创建整数型容器
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    //创建迭代器指向容器首指针
    vector<int>::iterator itbegin = v.begin(); 
    //创建迭代器指向容器尾指针
    vector<int>::iterator itend = v.end();

    //第一种遍历容器方法
    while(itbegin != itend)
    {
        cout << *itbegin << endl;
        itbegin ++;
    }

    // 第二种遍历容器方法
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }

    //第三种遍历容器方法
    for_each(itbegin,itend,printfint);



}

int main()
{
    test01();
    system("pause");
}