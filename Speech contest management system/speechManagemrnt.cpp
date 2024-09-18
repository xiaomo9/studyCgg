#include"speechManagement.h"
#include<algorithm>


SpeechManager::SpeechManager()
{
    this->init_SpeechManager();
    this->CreaterSpeaker(); // 创建选手
}

// 创建选手
void SpeechManager::CreaterSpeaker()
{
    string name_id = "ABCDEFGHIJKL";
    for(int i = 0; i< 12; i++)
    {
        string name = "选手";
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

// 管理系统属性初始化
void SpeechManager::init_SpeechManager()
{
    this->v1_speaker.clear();
    this->v2_speaker.clear();
    this->id_speaker.clear();
    this->epoch = 1;
}

// 菜单展示
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

// 退出系统
void SpeechManager::Exit_system()
{
    cout << "感谢使用本系统！" << endl;
    system("pause");
    exit(0);
}

// 抽签函数
void SpeechManager::speech_draw()
{
    if(this->epoch == 1)
    {
        cout << "开始第 << 1 >> 轮的抽签！" << endl;
        cout << "-------------------" << endl;
        random_shuffle(this->v1_speaker.begin(),this->v1_speaker.end());
        cout << "此轮的演讲顺序为：" << endl;
        for(vector<int>::iterator iter = this->v1_speaker.begin(); iter != this->v1_speaker.end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }

    if(this->epoch == 2){
        cout << "开始第 << 2 >> 轮的抽签！" << endl;
        random_shuffle(this->v2_speaker.begin(),this->v2_speaker.end());
        cout << "此轮的演讲顺序为：" << endl;
        for(vector<int>::iterator iter = this->v2_speaker.begin(); iter != this->v2_speaker.end(); ++iter)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }

    cout << "--------------------" << endl;
    system("pause");
}


// 开始比赛
void SpeechManager::Start_speech()
{
    // 第一轮
    // 开始抽签
    this->speech_draw();
    // 比赛（评分）
    // 展示结果


    // 第二轮
    // 开始抽签
    this->speech_draw();
    // 比赛（评分）
    // 展示结果
    // 保存成绩到文件中
}