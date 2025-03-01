#include <iostream>
using namespace std;
#include<time.h>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<iomanip>


class Student
{
private:
    string name;
    int stu_id;
    static int stu_num; // 静态类内成员变量 （属于类本身，直接用类调用）
    const int class_id; // 类内常量数据，初始化只能在构造函数列表上进行初始化
public:
    Student(string name1,int id):class_id(10),name(name1){
        this -> stu_id = id;
        
    }
    void print(){
        cout << "姓名：" << name << "\n学号：" << stu_id << "\n班级：" << class_id
        << "\n学生人数：" << stu_num << endl;
    }
    void say(){
        cout << "叫安保部！" << endl;
    }
    friend void output(Student s);//友元函数，可以访问类的private属性
};

void output(Student s){
    cout << "姓名：" << s.name << "\n学号：" << s.stu_id << "\n班级：" << s.class_id
        << "\n学生人数：" << s.stu_num << endl;
}

int Student :: stu_num = 40; // 
int main(){
    string s = "accca";
    int a,b,c,d;
    d = (a=4,b=16,c=32);
    cout << "s\\t" << endl;
    cout << endl ;
    system("pause");
}