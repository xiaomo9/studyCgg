#include<iostream>
#include <memory>
using namespace std;

class A; //ÉùÃ÷
class B;

class A{
public:
    ~A(){
        cout << "A::~A()" << endl;
    };
    shared_ptr<B> spb;
    //weak_ptr<B> spb;
};

class B{
public:
    ~B(){
        cout << "B::~B()" << endl;
    }
    shared_ptr<A> spa;
    // weak_ptr<A> spa;
};

int main(){
    shared_ptr<A> pa = make_shared<A>();
    shared_ptr<B> pb = make_shared<B>();
    pa->spb = pb;
    pb->spa = pa;
    cout << "pa::use_count:" << pa.use_count() << "\t" 
    << "pb::use_count:" << pb.use_count()<<endl;

    return 0;

}