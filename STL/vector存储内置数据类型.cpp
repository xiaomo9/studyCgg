# include<iostream>
using namespace std;
# include<vector>
# include<algorithm> //��׼�㷨ͷ�ļ�

void printfint(int a)
{
    cout << a << endl;
}

void test01()
{
    // ��������������
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    //����������ָ��������ָ��
    vector<int>::iterator itbegin = v.begin(); 
    //����������ָ������βָ��
    vector<int>::iterator itend = v.end();

    //��һ�ֱ�����������
    while(itbegin != itend)
    {
        cout << *itbegin << endl;
        itbegin ++;
    }

    // �ڶ��ֱ�����������
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }

    //�����ֱ�����������
    for_each(itbegin,itend,printfint);



}

int main()
{
    test01();
    system("pause");
}