# include<iostream>
using namespace std;
# include<vector>
#include<map>


class Speaker
{
public:
    string m_name;
    double m_scorce[2];
};


class SpeechManager
{
public:
    // ���캯��
    SpeechManager();
    // �˵���
    void Speech_menu();
    // �˳�ϵͳ0
    void Exit_system();
    // ��ʼ����1
    void Start_speech();
    // ��ǩ����
    void speech_draw();
    // ��������
    void Speech_contest();
    // ��ʾ���
    void Show_Scorce();
    // ������
    void Save_recore();

public: // ��Ա�����뷽��
    void init_SpeechManager();
    // �����ݽ�ѡ��
    void CreaterSpeaker();
    // ��һ�ֳ�Ա�������
    vector<int> v1_speaker;
    // �ڶ��ֳ�Ա�������
    vector<int> v2_speaker;
    // ���Ǿ���Ա�������
    vector<int> v_victort_speakrt;
    // ������Ա��Ӧ����
    map<int, Speaker> id_speaker;
    // ��������
    int epoch;
};

