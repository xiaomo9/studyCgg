# include<iostream>
using namespace std;
# include<fstream> //引入文件读写操作头文件

int main()
{
    ofstream file1; //创建流对象
    file1.open("test.txt",ios::out); // 打开文件所在位置，以及定义文件读写方式
    file1 << "我本坏蛋，无限嚣张" << endl; // 写入内容
    file1 << "我非英雄，广目无双" << endl;
    file1 << "欢迎来到德莱联盟" << endl;

    file1.close(); //关闭文件

    system("pause");
    return 0; 


}
