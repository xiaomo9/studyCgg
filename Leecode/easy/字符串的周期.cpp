# include<iostream>
using namespace std;

string str;
int lens;
bool judg(int T)
{
    for(int i =0; i<lens-T; ++i)
    {
        if(str[i] != str[i+T]) return 0;
    }
    return 1;
}

int main()
{   
    int n = 0;
    cin >> n;
    while (n--)
    {
        cout << "�����ַ�����" << endl;
        cin >> str; //��ȡҪ�����ڵ��ַ���
        lens = str.size();
        int ans = lens; // ������������ַ������ر�����
        for(int T = 1; T < lens/2+1; ++T)
        {
            if(lens%T == 0 && judg(T))
            {
                ans = T;
                break;
            }
        }
        cout << ans << endl;
    }
    system("pause");
}