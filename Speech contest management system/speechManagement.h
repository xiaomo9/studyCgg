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
    // ���������¼
    void road_recore();
    // ��ռ�¼
    void clear_record();


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
    // ������Ǿ���¼
    map<int, vector<string>> m_record;
    // ��������
    int epoch;
    // ���������Ƿ�Ϊ��
    bool FileIsEmpty;
};

