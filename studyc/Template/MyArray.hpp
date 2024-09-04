#include<iostream>
#pragma once
using namespace std;

template <class T>
class MyArray
{
public:
    T *m_arryaddress; // 数组位置
    int m_size; //数组大小
    int m_capacity; //数组容量

    // 构造函数
    MyArray(int capacity)
    {
        cout << "构造函数" << endl;
        this->m_arryaddress = new T[capacity];
        this->m_capacity = capacity;
        this->m_size = 0;
    }

    //拷贝构造函数
    MyArray(const MyArray &arry)
    {
        cout << "拷贝构造函数" << endl;
        this->m_size = arry.m_size;
        this->m_capacity = arry.m_capacity;
        // 防止浅拷贝
        this->m_arryaddress = new T[this->m_capacity];
        for (int i = 0; i<this->m_size; i++)
        {
            this->m_arryaddress[i] = arry.m_arryaddress[i];
        }
    }

    // 等号运算符重载，防止浅拷贝问题
    MyArray& operator=(const MyArray &arr)
    {
        cout << "等号运算符" << endl;
        // 清空原有数组
        if(this->m_arryaddress != NULL)
        {
            delete [] this->m_arryaddress;
            this->m_arryaddress = NULL;
        }
        // 拷贝
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        this->m_arryaddress = new T[this->m_capacity];
        for(int i = 0; i< arr.m_size ; i++)
        {
            this->m_arryaddress[i] = arr.m_arryaddress[i];
        }
        return *this;
    }

    // 尾插法
    void push_back(T c1)
    {
        if (this->m_capacity == this->m_size)
        {
            return;
        }
        this->m_arryaddress[this->m_size] = c1;
        this->m_size ++;
    }

    // 尾删法
    void del_back()
    {
        if(this->m_size==0)
        {
            return;
        }
        this->m_size --;
    }

    // 通过下标访问数组中的元素
    T& operator[](int index)
    {
        return this->m_arryaddress[index];
    }

    // 获取数组容量
    int get_capacity()
    {
        return this->m_capacity;
    }

    // 获取数组大小
    int get_size()
    {
        return this->m_size;
    }


    //析构函数
    ~MyArray()
    {
        cout << "析构函数" << endl;
        if(this->m_arryaddress != NULL)
        {
            delete [] this->m_arryaddress;
            this->m_arryaddress = NULL;
        }
    }

};

