# include<iostream>
using namespace std;
# include<vector>
#include<map>


class Speaker
{
public:
    string m_name;
    double m_scorce;
};


class SpeechManager
{
public:
    // ���캯��
    SpeechManager();
    // �˵���
    void Speech_menu();
    // �˳�ϵͳ
    void Exit_system();

public: // ��Ա�����뷽��
    void init_SpeechManager();
    // ��һ�ֳ�Ա�������
    vector<int> v1_speaker;
    // �ڶ��ֳ�Ա�������
    vector<int> v2_speaker;
    // ������Ա��Ӧ����
    map<int, Speaker> id_speaker;
    // ��������
    int epoch;
};

