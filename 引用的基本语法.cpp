#include<iostream>
using namespace std;

int main()
{
    //��һ������ȡ����
    int a = 10;
    int &b = a;//a�ı���Ϊb
    cout << "a= " << a << "  b = " << b << endl;

    b = 100;
    cout << "a= " << a << "  b = " << b << endl;


    system("pause");
    return 0;


}