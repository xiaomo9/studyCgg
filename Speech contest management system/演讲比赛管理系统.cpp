#include"speechManagement.h"

int main()
{
    SpeechManager sm;
    while (true)
    {
        sm.Speech_menu();

        int chance;
        cout << "������Ҫʹ�õĹ���:" << endl;
        cin >> chance;

        switch (chance)
        {
        case 0: //�˳�����
            sm.Exit_system();
            break;
        case 1: //��ʼ����
            sm.Start_speech();
            break;
        case 2: //��ѯ��¼
            break;
        case 3: // ɾ����¼
            break;
        
        default:
            break;
        }
        system("cls");
    }
    }
    
