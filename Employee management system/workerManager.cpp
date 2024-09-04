# include "workerManager.h"

// Ա����Ϣ��ʼ��
WorkerManager::WorkerManager()//���캯��
{
    ifstream isf;
    isf.open(FILENAME,ios::in); //���ļ�

    // ����ļ�������
    if (!isf.is_open()) 
    {   
        cout << "ְ����Ϣ�ļ�������" << endl;
        this->m_NumEmploy = 0; 
        this->WorkerArray = NULL;
        this->m_fileIsEmpty = true;
        isf.close();
        return;
    }

    // ����ļ�Ϊ��
    char ch;
    isf >> ch; // ��ȡһ���ֽڵ�����
    if (isf.eof()) // �ж������Ƿ��Ѿ�ָ���ļ�β��
    {
        cout << "�ļ�Ϊ�գ�" << endl;
        this->m_NumEmploy = 0; 
        this->WorkerArray = NULL;
        this->m_fileIsEmpty = true;
        isf.close();
        return;
    }

    // ����ļ���Ϊ��
    int num = GetNumEmploy();
    this->m_NumEmploy = num;
    this->m_fileIsEmpty = false;
    // �����µ�����ռ�
    this->WorkerArray = new Worker *[this->m_NumEmploy];
    this->initEmployArray(); // ���ó�ʼ����������ʼ������
}               

// ҳ��չʾ
void WorkerManager::ShowMenu()
{
    cout << "****************************" << endl;
    cout << "****��ӭʹ��ְ������ϵͳ***" << endl;
    cout << "***** 0���˳�������� *****" << endl;
    cout << "***** 1�����ְ����Ϣ *****" << endl;
    cout << "***** 2����ʾְ����Ϣ *****" << endl;
    cout << "***** 3��ɾ����ְְ�� *****" << endl;
    cout << "***** 4���޸�ְ����Ϣ *****" << endl;
    cout << "***** 5������ְ����Ϣ *****" << endl;
    cout << "***** 6�����ձ������ *****" << endl;
    cout << "***** 7����������ĵ� *****" << endl;
    cout << "****************************" << endl;

}

// �˳�ϵͳ����
void WorkerManager::ExitSystem()
{
    cout << "��лʹ�ñ�ϵͳ" << endl;
    system("pause");
    exit(0); //�˳�����
}

// ����ְ����Ϣ��ָ���ļ���
void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME,ios::out);

    for(int i = 0; i < this->m_NumEmploy; i++)
    {
        ofs << this->WorkerArray[i]->m_ID << " "
        << this->WorkerArray[i]->m_name << " "
        << this->WorkerArray[i]->m_PID << " " << endl;
    }
    ofs.close();
}

// ��ȡ��ǰְ������
int WorkerManager ::GetNumEmploy()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int ID;
    string name;
    int DID;
    int num = 0; // ����
    while (ifs >> ID && ifs >> name && ifs >> DID)
    {
        num ++;
    }
    return num;
}

// ��ʼ��ְ���б�
void WorkerManager ::initEmployArray()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);

    int id;
    string name;
    int did;
    int dix = 0;
    while(ifs >> id && ifs >> name && ifs >> did)
    {
        Worker *worker = NULL;
        if(did==1)
        {
            worker = new Employee(id,name,did);
        }
        else if(did == 2)
        {
            worker = new Manager(id, name, did);
        }
        else
        {
            worker = new Boss(id, name, did);
        }
        this->WorkerArray[dix] = worker;
        dix ++;
    }
}

// ���ְ��ϵͳ����
void WorkerManager::AddEmploy()
{
    int addnum;//Ҫ��ӵ�����
    cout << "������Ҫ��ӵ�����:" << endl;
    cin >> addnum;
    int id;// ���
    string name; //����
    int pid; //ְλ���

    //���Ա��
    if (addnum > 0)
    {
        int new_workernum = this->m_NumEmploy + addnum; //�µ�Ա������
        Worker ** NewSpace = new Worker *[new_workernum]; //�µ�Ա���б�洢
        // ��ԭ��Ա����Ϣת�Ƶ��µĿռ���
        if(this->WorkerArray != NULL)
        {
            for(int i = 0; i < this->m_NumEmploy; i++)
            {
                NewSpace[i] = this->WorkerArray[i];
            }
        }

        for(int i = 0; i<addnum; i++)
        {
            cout << "�����" << i+1 << "��Ա���ı��:" << endl;
            cin >> id;
            cout << "�����" << i+1 << "��Ա��������:" << endl;
            cin >> name;
            cout << "�����" << i+1 << "��Ա����ְλ:" << endl;
            cout << "1����ְͨ��" << endl;
            cout << "2������" << endl;
            cout << "3���ϰ�" << endl;
            cin >> pid;

            Worker * wk = NULL;
            switch (pid)
            {
            case 1:
                wk = new Employee(id,name,pid);
                break;
            case 2:
                wk = new Manager(id,name,pid);
                break;
            case 3:
                wk = new Boss(id,name,pid);
                break;
            default:
                break;
            }

            NewSpace[this->m_NumEmploy + i] = wk;
        }
        // �ͷ�ԭ�пռ�
        delete [] this->WorkerArray;
        // ����Ա���б�ָ��
        this->WorkerArray = NewSpace;
        // ����Ա������
        this->m_NumEmploy = new_workernum;
        cout << "�ɹ����" << addnum << "��ְ��" << endl;
        // �����ļ��Ƿ�Ϊ�ձ�ǩ
        this->m_fileIsEmpty = false;
        save(); // ��Ա����Ϣ���浽�ļ��С�
    }
    else
    {
        cout << "������������" << endl;
    }
    
    system("pause");
    system("cls");
}

// չʾְ����Ϣ����
void WorkerManager::Show_Employ()
{
    if (this->m_fileIsEmpty)
    {
        cout << "��ǰְ����ϢΪ�գ�" << endl;
    }
    else{
        for(int i = 0; i < this->m_NumEmploy; i++)
        {
            this->WorkerArray[i]->ShowInfo();// չʾְ����Ϣ��������
        }
    }
    system("pause");
    system("cls");
}

// �ж�Ҫ���ҵ�ְ���Ƿ����
int WorkerManager::Employ_IsExit(int id)
{
    int idx = -1;
    for(int i = 0; i < this->m_NumEmploy; i++)
    {
        if(this->WorkerArray[i]->m_ID == id)
        {
            idx = i;
            break;
        }
    }
    return idx;
}

// ɾ��ָ��ְ��
void WorkerManager::Del_Employ()
{
    if(this->m_fileIsEmpty)
    {
        cout << "ְ����Ϣ�ļ�Ϊ��" << endl;
    }
    else
    {
        int del_id;  // ��ȡҪɾ��ְ����ID
        cout << "������Ҫɾ����ְ��ID:" << endl;
        cin >> del_id;
        int idex; // �õ�Ҫɾ��Ա��������
        idex = this->Employ_IsExit(del_id);
        if(idex==-1)
        {
            cout << "��Ա��������" << endl;
        }
        else
        {
            for(int i = idex; i < this->m_NumEmploy-1; i++)
            {
                Worker *Temp = NULL;
                this->WorkerArray[i] = this->WorkerArray[i+1];
            }
            this->m_NumEmploy--;
            this->save();
            cout << "ɾ���ɹ�" << endl;
        }
    }
    system("pause");
    system("cls");
}

//�޸�ְ����Ϣ
void WorkerManager::Mod_Employ()
{
    if(this->m_fileIsEmpty) // ְ����Ϣ�Ƿ�Ϊ��
    {
        cout << "ְ����ϢΪ��" << endl;
    }
    else{
        int mod_id;
        cout << "����Ҫ�޸�ְ����ţ�" << endl;
        cin >> mod_id;
        int idex = this->Employ_IsExit(mod_id);
        if(idex == -1) // Ա���Ƿ����
        {
            cout << "��Ա��������" << endl;
        }
        else{
            Worker *wk = NULL;
            int id;
            string name;
            int pid;
            cout << "====�����޸ĺ����Ϣ��====" << endl;
            cout << "����ְ����ţ�" << endl;
            cin >> id;
            cout << "����ְ��������" << endl;
            cin >> name;
            cout << "����ְ��ְλ" << endl;
            cout << "1����ְͨ��" << endl;
            cout << "2������" << endl;
            cout << "3���ϰ�" << endl;
            cin >> pid;
            switch (pid)
            {
            case 1:
                wk = new Employee(id,name,pid);
                break;
            case 2:
                wk = new Manager(id,name,pid);
                break;
            case 3:
                wk = new Boss(id,name,pid);
                break;
            default:
                break;
            }
            this->WorkerArray[idex] = wk;
        }
        this->save();
    }
    system("pause");
    system("cls");
}

// ����ְ����Ϣ
void WorkerManager::Find_Employ()
{
    if (this->m_fileIsEmpty)
    {
        cout << "ְ����ϢΪ�գ�" << endl;
    }
    else
    {
        int chance;
        cout << "�������ְ���ķ�ʽ��" << endl;
        cout << "1����ְ����Ų���" << "\n"
             << "2����ְ����������" << endl;
        cin >> chance;
        if(chance == 1)
        {
            cout << "����Ҫ���ҵ�ְ����ţ�" << endl;
            int find_id;
            cin >> find_id;
            int ret = this->Employ_IsExit(find_id);
            if(ret != -1)
            {
                cout << "ְ�����Ϊ  " << find_id << "  ��Ա����Ϣ���£�" << endl;
                this->WorkerArray[ret]->ShowInfo();
            }
            else{cout << "δ�鵽���ˣ�" << endl;}
        }
        else if(chance == 2)
        {
            string find_name;
            cout << "������Ҫ���ҵ�ְ��������" << endl;
            cin >> find_name;
            bool flag = false; // �ж��Ƿ�鵽
            for(int i = 0; i < this->m_NumEmploy; i++)
            {
                if(this->WorkerArray[i]->m_name == find_name)
                {
                    flag = true;
                    cout << "����Ϊ  " << find_name << "  ��Ա����Ϣ���£�" << endl;
                    this->WorkerArray[i]->ShowInfo();
                }
            }
            if(flag == false)
            {
                cout << "δ�鵽������Ϣ��" << endl;
            }
        }
        else{cout << "��������ȷ���ҷ�ʽ��" << endl;}
    }

    system("pause");
    system("cls");
}


//  ���������
void WorkerManager::Sort_Employ()
{
    if (this->m_fileIsEmpty)
    {
        cout << "ְ����ϢΪ�գ�" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "��ѡ������ʽ��" << endl;
        cout << "1����ְ���������" << "\n"
             << "2����ְ����Ž���" << endl;
        int Select; // �û�ѡ�������ʽ
        cin >> Select;
        for(int i = 0; i < this->m_NumEmploy - 1; i++)
        {
            int minOrmax = i; //�����Сֵ����
            for(int j = i+1; j < this->m_NumEmploy; j++)
            {            
                if (Select == 1) // ��������
                {
                    if(this->WorkerArray[minOrmax]->m_ID > this->WorkerArray[j]->m_ID)
                    {
                        minOrmax = j;
                    }
                }
                if(Select == 2)
                {
                    if(this->WorkerArray[minOrmax]->m_ID < this->WorkerArray[j]->m_ID)
                    {
                        minOrmax = j;
                    }
                }
            }

            //����Сֵ�����ֵ�ᵽ��λ
            Worker * tem = this->WorkerArray[minOrmax];
            this->WorkerArray[minOrmax] = this->WorkerArray[i];
            this->WorkerArray[i] = tem;
        }
    this->save();
    cout << "������ɣ����ڵ���Ϣ�ṹ���£�" << endl;
    this->Show_Employ();
    }
}

// ���ְ����Ϣ
void WorkerManager::Cls_Employ()
{
    cout << "������������к�������" << endl;
    string password;
    cin >> password;
    if (password == "12345678")
    {
        cout << "ȷ���������������" << "\n"
         << "1��ȷ��" << "\n"
         << "2������" << endl;
         int select;
         cin >> select;
        if(select == 1)
        {
            ofstream osf;
            osf.open(FILENAME,ios::trunc); // ɾ��ԭ���ļ����½�ͬ���ļ�
            // ��ն�������������
            //���ÿ��ְ����Ϣ
            delete [] this->WorkerArray;
            this->WorkerArray = NULL;
            this->m_NumEmploy = 0;
            this->m_fileIsEmpty = true;
            cout << "������Ϣ���Ѿ��ɹ���գ�" << endl;
        }
    }
    else
    {
        cout << "����������޴�Ȩ�ޣ���";
    }
    system("pause");
    system("cls");
}

WorkerManager::~WorkerManager()
{   

}
