# include<iostream>
using namespace std;
# include<fstream>

int main()
{
    //�������ļ�
    ifstream readfile;
    //ָ���ļ���ַ
    readfile.open("test.txt",ios::in);
    //��ȡ�ļ�
    string readline;
    while (getline(readfile,readline))
    {
        cout << readline << endl;
    }



    //�ڶ��ַ���
    char buf[1024] = {0}; // �ַ������ʼ��
    while (readfile.getline(buf,sizeof(buf)))
    {
        cout << buf << endl;
    }
    
    readfile.close();
    system("pause");
    return 0;
    
}