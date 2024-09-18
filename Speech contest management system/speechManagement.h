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
    // 构造函数
    SpeechManager();
    // 菜单栏
    void Speech_menu();
    // 退出系统
    void Exit_system();

public: // 成员属性与方法
    void init_SpeechManager();
    // 第一轮成员编号容器
    vector<int> v1_speaker;
    // 第二轮成员编号容器
    vector<int> v2_speaker;
    // 编号与成员对应容器
    map<int, Speaker> id_speaker;
    // 比赛轮数
    int epoch;
};

