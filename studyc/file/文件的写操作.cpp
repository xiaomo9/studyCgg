# include<iostream>
using namespace std;
# include<fstream> //�����ļ���д����ͷ�ļ�

int main()
{
    ofstream file1; //����������
    file1.open("test.txt",ios::out); // ���ļ�����λ�ã��Լ������ļ���д��ʽ
    file1 << "�ұ���������������" << endl; // д������
    file1 << "�ҷ�Ӣ�ۣ���Ŀ��˫" << endl;
    file1 << "��ӭ������������" << endl;

    file1.close(); //�ر��ļ�

    system("pause");
    return 0; 


}
