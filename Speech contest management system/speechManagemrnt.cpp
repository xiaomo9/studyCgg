#include"speechManagement.h"

SpeechManager::SpeechManager()
{
    this->init_SpeechManager();
}


void SpeechManager::init_SpeechManager()
{
    this->v1_speaker.clear();
    this->v2_speaker.clear();
    this->id_speaker.clear();
    this->epoch = 1;
}


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

void SpeechManager::Exit_system()
{
    cout << "��лʹ�ñ�ϵͳ��" << endl;
    system("pause");
    exit(0);
}