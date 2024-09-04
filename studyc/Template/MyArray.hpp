#include<iostream>
#pragma once
using namespace std;

template <class T>
class MyArray
{
public:
    T *m_arryaddress; // ����λ��
    int m_size; //�����С
    int m_capacity; //��������

    // ���캯��
    MyArray(int capacity)
    {
        cout << "���캯��" << endl;
        this->m_arryaddress = new T[capacity];
        this->m_capacity = capacity;
        this->m_size = 0;
    }

    //�������캯��
    MyArray(const MyArray &arry)
    {
        cout << "�������캯��" << endl;
        this->m_size = arry.m_size;
        this->m_capacity = arry.m_capacity;
        // ��ֹǳ����
        this->m_arryaddress = new T[this->m_capacity];
        for (int i = 0; i<this->m_size; i++)
        {
            this->m_arryaddress[i] = arry.m_arryaddress[i];
        }
    }

    // �Ⱥ���������أ���ֹǳ��������
    MyArray& operator=(const MyArray &arr)
    {
        cout << "�Ⱥ������" << endl;
        // ���ԭ������
        if(this->m_arryaddress != NULL)
        {
            delete [] this->m_arryaddress;
            this->m_arryaddress = NULL;
        }
        // ����
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        this->m_arryaddress = new T[this->m_capacity];
        for(int i = 0; i< arr.m_size ; i++)
        {
            this->m_arryaddress[i] = arr.m_arryaddress[i];
        }
        return *this;
    }

    // β�巨
    void push_back(T c1)
    {
        if (this->m_capacity == this->m_size)
        {
            return;
        }
        this->m_arryaddress[this->m_size] = c1;
        this->m_size ++;
    }

    // βɾ��
    void del_back()
    {
        if(this->m_size==0)
        {
            return;
        }
        this->m_size --;
    }

    // ͨ���±���������е�Ԫ��
    T& operator[](int index)
    {
        return this->m_arryaddress[index];
    }

    // ��ȡ��������
    int get_capacity()
    {
        return this->m_capacity;
    }

    // ��ȡ�����С
    int get_size()
    {
        return this->m_size;
    }


    //��������
    ~MyArray()
    {
        cout << "��������" << endl;
        if(this->m_arryaddress != NULL)
        {
            delete [] this->m_arryaddress;
            this->m_arryaddress = NULL;
        }
    }

};

