# include<iostream>
using namespace std;
# include<fstream>

int main()
{
    //创建流文件
    ifstream readfile;
    //指定文件地址
    readfile.open("test.txt",ios::in);
    //读取文件
    string readline;
    while (getline(readfile,readline))
    {
        cout << readline << endl;
    }



    //第二种方法
    char buf[1024] = {0}; // 字符数组初始化
    while (readfile.getline(buf,sizeof(buf)))
    {
        cout << buf << endl;
    }
    
    readfile.close();
    system("pause");
    return 0;
    
}