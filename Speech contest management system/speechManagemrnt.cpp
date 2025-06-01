#include"speechManagement.h"
#include<algorithm>
#include<deque>
#include<map>
#include<numeric>
#include<fstream>

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
    this->v_victort_speakrt.clear();
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
    cout << endl;
    system("pause");
}

// 比赛函数
void SpeechManager::Speech_contest()
{
    cout << "---------开始第《《 " << this->epoch << " 》》 轮比赛---------" << endl;
    vector<int> game_speker; // 比赛成员
    multimap<double,int,greater<double>> map_speaker;  //用成绩排名的容器(降序)
    int num_speaker = 0;

    if(this->epoch == 1) // 获取第一轮比赛人员
    {
        game_speker = this->v1_speaker;
    }
    else if(this->epoch == 2) // 获取第二轮比赛人员
    {
        game_speker = this->v2_speaker;
    }

    // 开始为比赛成员打分
    for(vector<int>::iterator iter = game_speker.begin(); iter != game_speker.end(); iter++)
    {
        num_speaker ++;
        deque<double> d;
        //  获取每个人的分数
        for(int i = 0; i<10; i++)
        {
            double num = (rand() % 401 + 600) / 10.f;
            d.push_back(num);
        }
        sort(d.begin(),d.end(),greater<double>()); //排序
        d.pop_front(); // 去除最高分
        d.pop_back(); // 去除最低分

        double sum = accumulate(d.begin(),d.end(),0.0f);
        double ave = sum / (double)d.size();
        // 将成绩赋值给此人
        this->id_speaker[*iter].m_scorce[this->epoch-1] = ave;

        // 每六个人为一组
        map_speaker.insert(make_pair(ave,*iter));
        if(num_speaker % 6 == 0)
        {
            cout << "第《《 " << num_speaker / 6 << " 》》小组比赛成绩：" << endl;
            for(multimap<double,int>::iterator it = map_speaker.begin(); it != map_speaker.end(); ++it)
            {
                cout << "编号：" << (*it).second <<"  姓名：" << this->id_speaker[(*it).second].m_name
                << "  成绩：" << (*it).first << endl; 
            }
            cout << endl;
            //取前三名
            int count = 0 ;
            for(multimap<double,int>::iterator it = map_speaker.begin(); it != map_speaker.end() && count <3; it++,count++)
            {
                if(this->epoch == 1) //第一轮的前三名
                {
                    this->v2_speaker.push_back((*it).second);
                }
                if(this->epoch == 2) //第二轮的前三名
                {
                    this->v_victort_speakrt.push_back((*it).second);
                }
            }
            map_speaker.clear(); //清空临时容器  
        }
    }
    cout << "--------------第" << this->epoch << "轮比赛结束--------------" << endl;
    cout << endl;
    system("pause");
}

// 展示比赛结果
void SpeechManager::Show_Scorce()
{
    cout << "---------第 " << this->epoch << " 轮比赛晋级情况如下-----------：" << endl;
    vector<int> temp;
    if(this->epoch == 1)
    {
        temp = v2_speaker;
    }
    if(this->epoch == 2)
    {
        temp = v_victort_speakrt;
    }

    for(vector<int>::iterator iter = temp.begin(); iter != temp.end(); iter++)
    {
        cout << "编号：" << *iter << "  姓名：" << this->id_speaker[*iter].m_name
        << "  得分：" << this->id_speaker[*iter].m_scorce[this->epoch-1] << endl;;
    }
    cout << endl;
    system("pause");

}

// 保存比赛结果
void SpeechManager::Save_recore()
{
    ofstream ofs;
    ofs.open("speech.csv",ios::out | ios::app);
    for(vector<int>::iterator it = this->v_victort_speakrt.begin(); it != this->v_victort_speakrt.end(); it++)
    {
        ofs << this->id_speaker[*it].m_name << ',' << this->id_speaker[*it].m_scorce[1] << ',';
    }
    this->v2_speaker.clear();
    this->v_victort_speakrt.clear();
    ofs << endl;
    ofs.close();
}

// 加载往届数据
void SpeechManager::road_recore()
{
    ifstream ifs("speech.csv",ios::in); // 读取文件
    if(!ifs.is_open()) // 判断文件是否存在
    {
        this->FileIsEmpty = true;
        cout << "文件不存在！" << endl;
        system("pause");
        return;
    }

    char ch;
    ifs >> ch; 
    if(ifs.eof()) // 判断文件是否为空
    {
        cout << "文件为空！" << endl;
        ifs.close();
        system("pause");
        return;
    }

    this->FileIsEmpty = false;

    ifs.putback(ch); //前面读走的字符要读回来
    string data;

    int session = 1;
    while(ifs >> data)
    {   
        vector<string> s_record;
        int pos = -1; // ‘，’ 所在位置
        int start = 0;
        while(true)
        {
            pos = data.find(',',start);
            if(pos == -1) break;
            string temp = data.substr(start,pos-start);
            s_record.push_back(temp);
            start = pos + 1;
        }
        this->m_record.insert(make_pair(session,s_record));
        session ++;
    }
    // 输出往届信息
    cout << "===========往届冠亚军记录如下：==================" << endl;
    for(map<int,vector<string>>::iterator it = this->m_record.begin(); it != this->m_record.end(); it++)
    {
        cout << "第 " << (*it).first << "  届成绩：" << endl;
        cout << "冠军:" << (*it).second[0] << "  成绩：" << (*it).second[1] << endl;
        cout << "亚军:" << (*it).second[2] << "  成绩：" << (*it).second[3] << endl;
        cout << "季军:" << (*it).second[4] << "  成绩：" << (*it).second[5] << endl;
    }
    ifs.close();
    this->m_record.clear();
    system("pause");
}

// 开始比赛
void SpeechManager::Start_speech()
{
    // 第一轮
    // 开始抽签
    this->speech_draw();
    // 比赛（评分）
    this->Speech_contest();
    // 展示结果
    this->Show_Scorce();
    this->epoch += 1;

    // 第二轮
    // 开始抽签
    system("cls");
    this->speech_draw();
    // 比赛（评分）
    this->Speech_contest();
    // 展示结果
    this->Show_Scorce();
    this->epoch = 1;
    // 保存成绩到文件中
    this->Save_recore();
    system("cls");
    cout << "=======本届比赛圆满完成！=========" << endl;
    system("pause");
}

void SpeechManager::clear_record()
{
    cout << "是否要清空所有记录：" << endl
    << "1、是" << endl << "0、否" << endl;

    int change ;
    cin >> change;
    if(change == 1)
    {
        cout << "请输入密码：" << endl;
        int id;
        cin >> id;
        if(id == 1825518914)
        {
            //清空数据
            ofstream ofs;
            ofs.open("speech.csv",ios::trunc); // trunc删除原文件新建一个文件
            ofs.close();
            cout << "清空数据完毕！" << endl;
            system("pause");
        }
        else{
            cout << "密码错误，你没有权限！" << endl;
            system("pause");
        }
    }
    else  
    {
        system("pause");
        return;
    }
}