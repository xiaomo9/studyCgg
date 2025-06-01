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
    // 构造函数
    SpeechManager();
    // 菜单栏
    void Speech_menu();
    // 退出系统0
    void Exit_system();
    // 开始比赛1
    void Start_speech();
    // 抽签函数
    void speech_draw();
    // 比赛程序
    void Speech_contest();
    // 显示结果
    void Show_Scorce();
    // 保存结果
    void Save_recore();
    // 加载往届记录
    void road_recore();
    // 清空记录
    void clear_record();


public: // 成员属性与方法
    void init_SpeechManager();
    // 创建演讲选手
    void CreaterSpeaker();
    // 第一轮成员编号容器
    vector<int> v1_speaker;
    // 第二轮成员编号容器
    vector<int> v2_speaker;
    // 冠亚军成员编号容器
    vector<int> v_victort_speakrt;
    // 编号与成员对应容器
    map<int, Speaker> id_speaker;
    // 往届冠亚军记录
    map<int, vector<string>> m_record;
    // 比赛轮数
    int epoch;
    // 往届数据是否为空
    bool FileIsEmpty;
};

