# include<iostream>
using namespace std;
# pragma once // ��ֹͷ�ļ��ظ�����
# include"WorkerClass.h"
# include<fstream>
# define FILENAME "empFile.txt"

class WorkerManager
{
public:
    WorkerManager();//���캯��
    void ShowMenu();//�������� ҳ��չʾ
    void ExitSystem();//�˳�ϵͳ����
    void AddEmploy();// ���ְ����������
    void Show_Employ();// չʾְ����Ϣ
    void Del_Employ(); //ɾ��ְ����Ϣ
    void Mod_Employ(); // �޸�ְ����Ϣ
    void Find_Employ(); // ����ְ����Ϣ
    void Sort_Employ(); // ��ְ����Ž�������
    void Cls_Employ(); // ���ְ����Ϣ
    int Employ_IsExit(int id); //ְ���Ƿ���ڣ������ڷ��ض�Ӧ�����������ڷ���-1
    void save();// ��Ա����Ϣ�洢��ָ���ļ���
    int GetNumEmploy(); // ��ȡ��ǰְ������
    void initEmployArray(); // ��ʼ��ְ���б�
public:
    int m_NumEmploy; //ĿǰԱ������
    Worker ** WorkerArray; //Ա���б�
    bool m_fileIsEmpty; //�ж�Ա����Ϣ�ļ��Ƿ����
    ~WorkerManager();
};