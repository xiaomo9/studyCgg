#include"speechManagement.h"
#include<time.h>

int main()
{
    srand((unsigned int) time(NULL));
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
            sm.road_recore();
            break;
        case 3: // ɾ����¼
            sm.clear_record();
            break;
        
        default:
            break;
        }
        system("cls");
    }
    }
    
