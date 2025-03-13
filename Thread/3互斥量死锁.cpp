#include<iostream>
using namespace std;
#include<thread>
#include<mutex>

mutex m1,m2;

void add(){
    for(int i=0; i<10;++i){
        m1.lock();
        cout << "1" << endl;
        m2.lock();
        cout << "2" << endl;
        m1.unlock();
        cout << "3" << endl;
        m2.unlock();
        cout << "4" << endl;
    }

}

void add2(){
    for(int i=0; i<10; ++i){
        m2.lock();
        cout << "a" << endl;
        m1.lock();
        cout << "b" << endl;
        m2.unlock();
        cout << "c" << endl;
        m1.unlock();        
        cout << "d" << endl;
    }

}


int main(){
    thread t1(add);
    thread t2(add2);
    t1.join();
    t2.join();
    cout << "over" << endl;
    return 0;
}