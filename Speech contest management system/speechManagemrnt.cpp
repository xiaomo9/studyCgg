#include"speechManagement.h"
#include<algorithm>


SpeechManager::SpeechManager()
{
    this->init_SpeechManager();
    this->CreaterSpeaker(); // ����ѡ��
}

// ����ѡ��
void SpeechManager::CreaterSpeaker()
{
    string name_id = "ABCDEFGHIJKL";
    for(int i = 0; i< 12; i++)
    {
        string name = "ѡ��";
        name += name_id[i];
        Speaker person;
        person.m_name = name;
        for(int i = 0; i<2; ++i)
        {
            person.m_scorce[i] = 0;
        }
        int id = 1001 + i;
        this->v1_speaker.push_back(id);
        this->id_speaker.insert(make_pair(id,person));
    }
 }

// ����ϵͳ���Գ�ʼ��
void SpeechManager::init_SpeechManager()
{
    this->v1_speaker.clear();
    this->v2_speaker.clear();
    this->id_speaker.clear();
    this->epoch = 1;
}

// �˵�չʾ
void SpeechManager::Speech_menu()
{
    cout << "********************************" << endl;
    cout << "********��ӭ�μ��ݽ�����********" << endl;
    cout << "********1����ʼ�ݽ�����*********" << endl;
    cout << "********2���鿴�����¼*********" << endl;
    cout << "********3����ձ�����¼*********" << endl;
    cout << "********0���˳���������*********" << endl;
    cout << endl;
}

// �˳�ϵͳ
void SpeechManager::Exit_system()
{
    cout << "��лʹ�ñ�ϵͳ��" << endl;
    system("pause");
    exit(0);
}

// ��ǩ����
void SpeechManager::speech_draw()
{
    if(this->epoch == 1)
    {
        cout << "��ʼ�� << 1 >> �ֵĳ�ǩ��" << endl;
        cout << "-------------------" << endl;
        random_shuffle(this->v1_speaker.begin(),this->v1_speaker.end());
        cout << "���ֵ��ݽ�˳��Ϊ��" << endl;
        for(vector<int>::iterator iter = this->v1_speaker.begin(); iter != this->v1_speaker.end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }

    if(this->epoch == 2){
        cout << "��ʼ�� << 2 >> �ֵĳ�ǩ��" << endl;
        random_shuffle(this->v2_speaker.begin(),this->v2_speaker.end());
        cout << "���ֵ��ݽ�˳��Ϊ��" << endl;
        for(vector<int>::iterator iter = this->v2_speaker.begin(); iter != this->v2_speaker.end(); ++iter)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }

    cout << "--------------------" << endl;
    system("pause");
}


// ��ʼ����
void SpeechManager::Start_speech()
{
    // ��һ��
    // ��ʼ��ǩ
    this->speech_draw();
    // ���������֣�
    // չʾ���


    // �ڶ���
    // ��ʼ��ǩ
    this->speech_draw();
    // ���������֣�
    // չʾ���
    // ����ɼ����ļ���
}