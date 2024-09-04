# include<iostream>

using namespace std;

int add(int num1, int num2)
{
    return num1 + num2;
}

int main(void) 
{

    int num1 = 10;
    int num2 = 10;
    int c = add(num1, num2);
    cout << "num1 + num2 = " << c << endl;

    system("pause");
    return 0;
}