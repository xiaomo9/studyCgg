#include"speechManagement.h"

int main()
{
    SpeechManager sm;
    while (true)
    {
        sm.Speech_menu();

        int chance;
        cout << "请输入要使用的功能:" << endl;
        cin >> chance;

        switch (chance)
        {
        case 0: //退出程序
            sm.Exit_system();
            break;
        case 1: //开始比赛
            sm.Start_speech();
            break;
        case 2: //查询记录
            break;
        case 3: // 删除记录
            break;
        
        default:
            break;
        }
        system("cls");
    }
    }
    
