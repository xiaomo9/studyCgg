#include<iostream>
using namespace std;
#include<mutex>

mutex mtx;

void afdd(int &x){
    for(int i = 0;i< 100000;i++){
        // ¼ÓÈë»¥³âËø
        mtx.lock();
        x ++;
        mtx.unlock();
    }
}
int a = 0;
int main (){
    thread thr1(afdd,ref(a));
    thread thr2(afdd,ref(a));
    thr1.join();
    thr2.join();
    cout << a << endl;
}