#include<iostream>
using namespace std;
#include<string>
int main()
{
	int m;
	cin >> m;
	if (cin.good())		//这也可以写成 if (cin>>m)
	{
		cout << "cin.good()=" << cin.good() << endl;
		cout << "m=" << m << endl;
	}
	else				//这也可以写成 if (!(cin>>m))
	{
		cout << "cin.good()=" << cin.good() << endl;
		cout << "输入的数据类型错误\n";
		cin.clear(); // 让键盘进入可输入模式
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
