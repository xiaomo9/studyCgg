#include<iostream>
using namespace std;
#include<string>
int main()
{
	int m;
	cin >> m;
	if (cin.good())		//��Ҳ����д�� if (cin>>m)
	{
		cout << "cin.good()=" << cin.good() << endl;
		cout << "m=" << m << endl;
	}
	else				//��Ҳ����д�� if (!(cin>>m))
	{
		cout << "cin.good()=" << cin.good() << endl;
		cout << "������������ʹ���\n";
		cin.clear(); // �ü��̽��������ģʽ
		while (cin.get() != '\n')
		{
			continue;
		}
	}
	string str;
	cin >> str;
	cout << str<< endl;
    system("pause");
    return 0;
}
