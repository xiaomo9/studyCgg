# include <iostream>
using namespace std;


template<typename T>
void myswap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}


int main()
{
    // ģ��Ļ����﷨
    int a = 10;
    int b = 20;
    myswap(a,b);
    cout << a << endl;
    cout << b << endl;
    system("pause");
    system("cls");
    return 0;
}