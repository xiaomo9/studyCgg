#include<iostream>
using namespace std;
#include"workerManager.h"
#include"WorkerClass.h"


int main()
{
    WorkerManager wm;

    while(true)
    {
        wm.ShowMenu();
        int choice;
        cout << "����Ҫʹ�õĹ��ܣ�" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0: //�˳�ϵͳ
            wm.ExitSystem();
            break;
        case 1: //���ְ����Ϣ
            wm.AddEmploy();
            break;
        case 2: //չʾְ����Ϣ
            wm.Show_Employ();
            break;
        case 3: //ɾ��ְ����Ϣ
            wm.Del_Employ();
            break;           
        case 4: //�޸�ְ����Ϣ
            wm.Mod_Employ();
            break;
        case 5:// ����ְ����Ϣ
            wm.Find_Employ();
            break;
        case 6:// ���ձ������
            wm.Sort_Employ();
            break;
        case 7: // �����Ϣ
            wm.Cls_Employ();
            break;

        default:
            break;
        }

    }


    system("pause");
    return 0;
}