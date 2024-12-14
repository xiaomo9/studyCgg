#include"speechManagement.h"
#include<algorithm>
#include<deque>
#include<map>
#include<numeric>
#include<fstream>

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
    this->v_victort_speakrt.clear();
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
    cout << endl;
    system("pause");
}

// ��������
void SpeechManager::Speech_contest()
{
    cout << "---------��ʼ�ڡ��� " << this->epoch << " ���� �ֱ���---------" << endl;
    vector<int> game_speker; // ������Ա
    multimap<double,int,greater<double>> map_speaker;  //�óɼ�����������(����)
    int num_speaker = 0;

    if(this->epoch == 1) // ��ȡ��һ�ֱ�����Ա
    {
        game_speker = this->v1_speaker;
    }
    else if(this->epoch == 2) // ��ȡ�ڶ��ֱ�����Ա
    {
        game_speker = this->v2_speaker;
    }

    // ��ʼΪ������Ա���
    for(vector<int>::iterator iter = game_speker.begin(); iter != game_speker.end(); iter++)
    {
        num_speaker ++;
        deque<double> d;
        //  ��ȡÿ���˵ķ���
        for(int i = 0; i<10; i++)
        {
            double num = (rand() % 401 + 600) / 10.f;
            d.push_back(num);
        }
        sort(d.begin(),d.end(),greater<double>()); //����
        d.pop_front(); // ȥ����߷�
        d.pop_back(); // ȥ����ͷ�

        double sum = accumulate(d.begin(),d.end(),0.0f);
        double ave = sum / (double)d.size();
        // ���ɼ���ֵ������
        this->id_speaker[*iter].m_scorce[this->epoch-1] = ave;

        // ÿ������Ϊһ��
        map_speaker.insert(make_pair(ave,*iter));
        if(num_speaker % 6 == 0)
        {
            cout << "�ڡ��� " << num_speaker / 6 << " ����С������ɼ���" << endl;
            for(multimap<double,int>::iterator it = map_speaker.begin(); it != map_speaker.end(); ++it)
            {
                cout << "��ţ�" << (*it).second <<"  ������" << this->id_speaker[(*it).second].m_name
                << "  �ɼ���" << (*it).first << endl; 
            }
            cout << endl;
            //ȡǰ����
            int count = 0 ;
            for(multimap<double,int>::iterator it = map_speaker.begin(); it != map_speaker.end() && count <3; it++,count++)
            {
                if(this->epoch == 1) //��һ�ֵ�ǰ����
                {
                    this->v2_speaker.push_back((*it).second);
                }
                if(this->epoch == 2) //�ڶ��ֵ�ǰ����
                {
                    this->v_victort_speakrt.push_back((*it).second);
                }
            }
            map_speaker.clear(); //�����ʱ����  
        }
    }
    cout << "--------------��" << this->epoch << "�ֱ�������--------------" << endl;
    cout << endl;
    system("pause");
}

// չʾ�������
void SpeechManager::Show_Scorce()
{
    cout << "---------�� " << this->epoch << " �ֱ��������������-----------��" << endl;
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
        cout << "��ţ�" << *iter << "  ������" << this->id_speaker[*iter].m_name
        << "  �÷֣�" << this->id_speaker[*iter].m_scorce[this->epoch-1] << endl;;
    }
    cout << endl;
    system("pause");

}

// ����������
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

// ������������
void SpeechManager::road_recore()
{
    ifstream ifs("speech.csv",ios::in); // ��ȡ�ļ�
    if(!ifs.is_open()) // �ж��ļ��Ƿ����
    {
        this->FileIsEmpty = true;
        cout << "�ļ������ڣ�" << endl;
        system("pause");
        return;
    }

    char ch;
    ifs >> ch; 
    if(ifs.eof()) // �ж��ļ��Ƿ�Ϊ��
    {
        cout << "�ļ�Ϊ�գ�" << endl;
        ifs.close();
        system("pause");
        return;
    }

    this->FileIsEmpty = false;

    ifs.putback(ch); //ǰ����ߵ��ַ�Ҫ������
    string data;

    int session = 1;
    while(ifs >> data)
    {   
        vector<string> s_record;
        int pos = -1; // ������ ����λ��
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
    // ���������Ϣ
    cout << "===========������Ǿ���¼���£�==================" << endl;
    for(map<int,vector<string>>::iterator it = this->m_record.begin(); it != this->m_record.end(); it++)
    {
        cout << "�� " << (*it).first << "  ��ɼ���" << endl;
        cout << "�ھ�:" << (*it).second[0] << "  �ɼ���" << (*it).second[1] << endl;
        cout << "�Ǿ�:" << (*it).second[2] << "  �ɼ���" << (*it).second[3] << endl;
        cout << "����:" << (*it).second[4] << "  �ɼ���" << (*it).second[5] << endl;
    }
    ifs.close();
    this->m_record.clear();
    system("pause");
}

// ��ʼ����
void SpeechManager::Start_speech()
{
    // ��һ��
    // ��ʼ��ǩ
    this->speech_draw();
    // ���������֣�
    this->Speech_contest();
    // չʾ���
    this->Show_Scorce();
    this->epoch += 1;

    // �ڶ���
    // ��ʼ��ǩ
    system("cls");
    this->speech_draw();
    // ���������֣�
    this->Speech_contest();
    // չʾ���
    this->Show_Scorce();
    this->epoch = 1;
    // ����ɼ����ļ���
    this->Save_recore();
    system("cls");
    cout << "=======�������Բ����ɣ�=========" << endl;
    system("pause");
}

void SpeechManager::clear_record()
{
    cout << "�Ƿ�Ҫ������м�¼��" << endl
    << "1����" << endl << "0����" << endl;

    int change ;
    cin >> change;
    if(change == 1)
    {
        cout << "���������룺" << endl;
        int id;
        cin >> id;
        if(id == 1825518914)
        {
            //�������
            ofstream ofs;
            ofs.open("speech.csv",ios::trunc); // truncɾ��ԭ�ļ��½�һ���ļ�
            ofs.close();
            cout << "���������ϣ�" << endl;
            system("pause");
        }
        else{
            cout << "���������û��Ȩ�ޣ�" << endl;
            system("pause");
        }
    }
    else  
    {
        system("pause");
        return;
    }
}