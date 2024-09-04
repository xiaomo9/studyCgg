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

//����Person���� (һ������ѡ��)
void createvector(vector<Person>&v)
{   
    string playernum = "ABCDE";
    for (int i =0; i<5 ;i++)
    {
        string player = "ѡ��" ;
        player += playernum[i];
        int scorce = 0;
        Person p(player,scorce);
        v.push_back(p);
    }
}


// ��ί��֣�ʮ����ί��ȥ�������ͷ֣��ó�ƽ���֣�
void mark(vector<Person>&v)
{
    for(vector<Person>::iterator it = v.begin() ; it!=v.end() ; it++)
    {
        deque<int> d1;
        for(int i =0; i< 10; i++)
        {
            int score1;
            score1 = rand() % 41 + 60 ;//�õ�60-100�������
            d1.push_back(score1);
        }
        int num = 0;// �ܷ�
        sort(d1.begin(), d1.end()); //����
        d1.pop_front(); //ȥ����߷� 
        d1.pop_back(); //ȥ����ͷ�
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
        cout << (*it).m_name << " ������" << (*it).m_score << endl;
    } 

}

int main()
{
    srand((unsigned int) time(NULL)); // ���������
    vector<Person> v; 
    createvector(v); //����ѡ��
    mark(v); // ��ί����
    printpersonarry(v); //��ӡ��Ϣ
    system("pause");
}