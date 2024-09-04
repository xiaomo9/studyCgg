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
        cout << "输入要使用的功能：" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0: //退出系统
            wm.ExitSystem();
            break;
        case 1: //添加职工信息
            wm.AddEmploy();
            break;
        case 2: //展示职工信息
            wm.Show_Employ();
            break;
        case 3: //删除职工信息
            wm.Del_Employ();
            break;           
        case 4: //修改职工信息
            wm.Mod_Employ();
            break;
        case 5:// 查找职工信息
            wm.Find_Employ();
            break;
        case 6:// 按照编号排序、
            wm.Sort_Employ();
            break;
        case 7: // 清空信息
            wm.Cls_Employ();
            break;

        default:
            break;
        }

    }


    system("pause");
    return 0;
}