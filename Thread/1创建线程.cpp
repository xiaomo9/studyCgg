#include<iostream>
#include<thread>
using namespace std;

void printhell(int &a){
    a ++;
}

int main(){
    int a = 1;
    thread thread1(printhell,ref(a));
    if(thread1.joinable()){
        thread1.join();
    }
    cout << a << endl;
    return 0;
}