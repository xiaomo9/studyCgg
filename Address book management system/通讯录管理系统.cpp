/*
ͨѶ¼����ϵͳ
ʵ����Ҫ�������£�
1�������ϵ�ˣ��������������Ա����䡢��ϵ�绰����ͥסַ������¼1000�ˡ�
2����ʾ��ϵ�ˣ���ʾͨѶ¼��������ϵ����Ϣ��
3��ɾ����ϵ�ˣ���������ɾ��ָ����ϵ�ˡ�
4��������ϵ�ˣ�������������ָ����ϵ����Ϣ��
5���޸���ϵ�ˣ��������������޸�ָ����ϵ����Ϣ��
6�������ϵ�ˣ����ͨѶ¼��������Ϣ��
7���˳�ͨѶ¼���˳���ǰʹ�õ�ͨѶ¼��
*/

# include <iostream>
# include<string>
using namespace std;
# define MAX 1000
# define password "123456"
// ������ϵ�˽ṹ��
struct person
{
    string name;
    int sex; // 1����  2��Ů
    int age;
    string phone;
    string address;
};

// ����ͨѶ¼�ṹ��
struct AddressBook
{
    // ������ϵ�˽ṹ������
    struct person personArray[MAX];
    int add_size; // ͨѶ¼ʵ������
};

// ���幦�ܲ˵�����
void showmenu()
{
    cout << "***** ͨѶ¼����ϵͳ *****" << endl;
    cout << "***** 1�������ϵ�� *****" << endl;
    cout << "***** 2����ʾ��ϵ�� *****" << endl;
    cout << "***** 3��ɾ����ϵ�� *****" << endl;
    cout << "***** 4��������ϵ�� *****" << endl;
    cout << "***** 5���޸���ϵ�� *****" << endl;
    cout << "***** 6�������ϵ�� *****" << endl;
    cout << "***** 0���˳�ͨѶ¼ *****" << endl;
    cout << "*************************" << endl;
}

// ���������ϵ�˺���
void addperson(struct AddressBook * abs)
{
    if (abs->add_size == 1000)
    {
        cout << "�����Ѿ������������" << endl;
        return;
    }
    else
    {
        // ����
        string name;
        cout << "����������" << endl;
        cin >> name;
        abs -> personArray[abs->add_size].name = name;
        // �Ա�
        int sex; // 1����  2��Ů
        while (true) //�ж��Ƿ���������
        {   
            cout << "�����Ա�  1--��   2--Ů" << endl;
            cin >> sex;
            if(sex == 1 || sex == 2)
            {
                abs ->personArray[abs->add_size].sex = sex;
                break;
            }
            else
            {
                cout << "�����������������룡" << endl;
            }
        }
        // ����
        int age;
        cout << "�������䣺" << endl;
        while (true)// �ж����������Ƿ���ȷ
        {   
            cin >> age;
            if (cin.good())
            {
                abs ->personArray[abs->add_size].age = age;
                break;
            }
            else
            {
                cout << "��������ȷ�ĸ�ʽ��" << endl;
                cin.clear(); // ��һ�����Ҫ����cin���±��Ϊ��ȷ���Դﵽ���������Ŀ�� 	
                while (cin.get() != '\n')		//�������֮ǰcin������������ ,���ǽ�������������ݶ����ĵ�
			    {
                    continue;
                }
            }
        }
        //�绰
        string phone;
        cout << "����绰���룺" << endl;
        cin >> phone;
        abs ->personArray[abs->add_size].phone = phone;
        // ��ͥסַ
        string address;
        cout << "�����ͥסַ��" << endl;
        cin >> address;
        abs ->personArray[abs ->add_size].address = address;
        abs ->add_size ++;
        cout << "��ϵ����ӳɹ���" << endl;
        system("pause");
        system("cls");
    }
}


// ������ʾ��ϵ�˺���
void showperson(struct AddressBook *abs)
{
    if(abs->add_size == 0)
    {
        cout << " ��¼Ϊ�գ�����ϵ����Ϣ" << endl;
    }
    else
    {
        for(int i = 0; i< abs->add_size; i++ )
        {
            cout << "������" << abs->personArray[i].name << "\t"
            << "  ���䣺" << abs->personArray[i].age << "\t"
            << "  �Ա�" << (abs->personArray[i].sex == 1 ? "��" : "Ů") << "\t"//�������Ա�ת��Ϊ��Ӧ����Ů
            << "  �绰��" << abs->personArray[i].phone << "\t"
            << "  ��ͥ��ַ��" << abs->personArray[i].address <<endl;
        }
    }
    system("pause");
    system("cls");
}


// ��������ϵ���Ƿ���ں���
int Isexist(struct AddressBook *abs, string name)
{
    for (int i = 0; i< abs->add_size; i++)
    {
        if(abs->personArray[i].name == name)
        {
            return i; //����ָ����ϵ���±�
        }
    }
    
    return -1; // ��ȫ�������껹��û���ҵ��򷵻�-1
}


// ����ɾ����ϵ�˺���
void delperson(struct AddressBook *abs)
{
    string name;
    cout << "����Ҫɾ����ϵ�˵�������" << endl;
    cin >> name;
    int idx = Isexist(abs, name);
    if (idx != -1)
    {
        for (int i = idx; i<abs->add_size; i++)
        {
            abs->personArray[i] = abs->personArray[i+1];
        }
        abs->add_size--;
        cout << "ɾ���ɹ�" << endl;
    }
    else 
    {
        cout << "����ϵ�˲����ڣ�" << endl;
    }
    system("pause");
    system("cls");
}


// ���������ϵ�˺���
void findperson(struct AddressBook *abs)
{
    cout << "����Ҫ������ϵ��������" << endl;
    string name;
    cin >> name;
    int idx = Isexist(abs,name);

    if (idx != -1)
    {
        cout << "������" << abs->personArray[idx].name 
        << "  ���䣺" << abs->personArray[idx].age
        << "  �Ա�" << (abs->personArray[idx].sex == 1 ? "��" : "Ů")
        << "  �绰��" << abs->personArray[idx].phone 
        << "  ��ͥ��ַ��" << abs->personArray[idx].address <<endl;
    }
    else 
    {
        cout << "����ϵ�˲����ڣ�" << endl;
    }
    system("pause");
    system("cls");
}


// �����޸���ϵ�˺���
void editperson(struct AddressBook * abs)
{
    cout << "����Ҫ�޸���ϵ��������" << endl;
    string name;
    cin >> name;
    int idx = Isexist(abs,name);

    if (idx!=-1)
    {
        // ����
        string name;
        cout << "����������" << endl;
        cin >> name;
        abs -> personArray[idx].name = name;
        // �Ա�
        int sex; // 1����  2��Ů
        while (true) //�ж��Ƿ���������
        {   
            cout << "�����Ա�  1--��   2--Ů" << endl;
            cin >> sex;
            if(sex == 1 || sex == 2)
            {
                abs ->personArray[idx].sex = sex;
                break;
            }
            else
            {
                cout << "�����������������룡" << endl;
            }
        }
        // ����
        int age;
        cout << "�������䣺" << endl;
        while (true)// �ж����������Ƿ���ȷ
        {   
            cin >> age;
            if (cin.good())
            {
                abs ->personArray[idx].age = age;
                break;
            }
            else
            {
                cout << "��������ȷ�ĸ�ʽ��" << endl;
                cin.clear(); // ��һ�����Ҫ����cin���±��Ϊ��ȷ���Դﵽ���������Ŀ�� 	
                while (cin.get() != '\n')		//�������֮ǰcin������������ ,���ǽ�������������ݶ����ĵ�
			    {
                    continue;
                }
            }
        }
        //�绰
        string phone;
        cout << "����绰���룺" << endl;
        cin >> phone;
        abs ->personArray[idx].phone = phone;
        // ��ͥסַ
        string address;
        cout << "�����ͥסַ��" << endl;
        cin >> address;
        abs ->personArray[idx].address = address;
        cout << "�޸ĳɹ���" << endl;
    }
        else 
    {
        cout << "����ϵ�˲����ڣ�" << endl;
    }
    system("pause");
    system("cls");
}


//������պ���
void clearperson(struct AddressBook *abs)
{
    cout << "������boot���룺"<< endl;
    string numid;
    cin >> numid;

    if (numid == password)
    {
        abs->add_size = 0;
        cout << " ͨѶ¼�Ѿ��������" << endl;
    }
    else
    {
        cout << "��Ǹ���������û��Ȩ��ִ�д˲�����";
    }
    system("pause");
    system("cls");

}


// ������
int main ()
{
    int select;
    // ��ʼ��ͨѶ¼�ṹ��
    struct AddressBook abs;
    abs.add_size = 0;
    while (true)
    {
        showmenu();
        cout << "����Ҫѡ��Ĺ��ܣ�" << endl;
        cin >> select;

        //���ܷ�֧
        switch (select)
        {
        case 1: // 1�������ϵ��
            addperson(&abs);
            break;
        case 2: // 2����ʾ��ϵ��
            showperson(&abs);
            break;
        case 3: // 3��ɾ����ϵ��
            delperson(&abs);
            break;
        case 4: // 4��������ϵ��
            findperson(&abs);
            break;
        case 5: // 5���޸���ϵ��
            editperson(&abs);
            break;
        case 6: // 6�������ϵ��
            clearperson(&abs);
            break;
        case 0: // 0���˳�ͨѶ¼
            cout << "��ӭ���´�ʹ�ã�" << endl;
            system("pause");
            return 0 ;
            break;
        default:
            break;
        }

    }
    
    system("pause");
    return 0 ;
}


