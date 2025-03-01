#include<iostream>
using namespace std;


int fun(int a,int b){
    return a+b;
}
int fun2(int a,int b){
    return a-b;
}

int main(){
    int a = 1, b = 2;
    cout << fun(a,b) << endl;
    return 0;
    system("pause");
}