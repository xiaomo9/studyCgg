#include<iostream>
#include<vector>
#include<deque>
#include<ctime>
#include<algorithm>
using namespace std;

class Person
{
public:
    Person(string name, int score)
    {
        this->m_name = name;
        this->m_score = score;
    }

    string m_name;
    int m_score;
};

//创建Person容器 (一共五名选手)
void createvector(vector<Person>&v)
{   
    string playernum = "ABCDE";
    for (int i =0; i<5 ;i++)
    {
        string player = "选手" ;
        player += playernum[i];
        int scorce = 0;
        Person p(player,scorce);
        v.push_back(p);
    }
}


// 评委打分（十名评委，去掉最高最低分，得出平均分）
void mark(vector<Person>&v)
{
    for(vector<Person>::iterator it = v.begin() ; it!=v.end() ; it++)
    {
        deque<int> d1;
        for(int i =0; i< 10; i++)
        {
            int score1;
            score1 = rand() % 41 + 60 ;//得到60-100的随机数
            d1.push_back(score1);
        }
        int num = 0;// 总分
        sort(d1.begin(), d1.end()); //排序
        d1.pop_front(); //去除最高分 
        d1.pop_back(); //去除最低分
        for(deque<int>::iterator dit = d1.begin(); dit != d1.end(); dit++)
        {
            num += (*dit);
        }
        num /= d1.size();
        (*it).m_score = num;
    }

}

void printpersonarry(vector<Person>&v)
{
    for(vector<Person>::iterator it = v.begin(); it!=v.end(); it++)
    {
        cout << (*it).m_name << " 分数：" << (*it).m_score << endl;
    } 

}

int main()
{
    srand((unsigned int) time(NULL)); // 随机数种子
    vector<Person> v; 
    createvector(v); //创建选手
    mark(v); // 评委评分
    printpersonarry(v); //打印信息
    system("pause");
}