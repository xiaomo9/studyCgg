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
    cout << "********欢迎参加演讲比赛********" << endl;
    cout << "********1、开始演讲比赛*********" << endl;
    cout << "********2、查看往届记录*********" << endl;
    cout << "********3、清空比赛记录*********" << endl;
    cout << "********0、退出比赛程序*********" << endl;
    cout << endl;
}

void SpeechManager::Exit_system()
{
    cout << "感谢使用本系统！" << endl;
    system("pause");
    exit(0);
}