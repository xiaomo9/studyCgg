# include<iostream>
using namespace std;
# pragma once // 防止头文件重复包含
# include"WorkerClass.h"
# include<fstream>
# define FILENAME "empFile.txt"

class WorkerManager
{
public:
    WorkerManager();//构造函数
    void ShowMenu();//函数声明 页面展示
    void ExitSystem();//退出系统功能
    void AddEmploy();// 添加职工函数声明
    void Show_Employ();// 展示职工信息
    void Del_Employ(); //删除职工信息
    void Mod_Employ(); // 修改职工信息
    void Find_Employ(); // 查找职工信息
    void Sort_Employ(); // 按职工编号进行排序
    void Cls_Employ(); // 清空职工信息
    int Employ_IsExit(int id); //职工是否存在，若存在返回对应索引，不存在返回-1
    void save();// 将员工信息存储到指定文件下
    int GetNumEmploy(); // 获取当前职工个数
    void initEmployArray(); // 初始化职工列表
public:
    int m_NumEmploy; //目前员工个数
    Worker ** WorkerArray; //员工列表
    bool m_fileIsEmpty; //判断员工信息文件是否存在
    ~WorkerManager();
};