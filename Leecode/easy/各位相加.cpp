#include<iostream>
using namespace std;

/*
����һ���Ǹ����� num������������λ�ϵ�������ӣ�ֱ�����Ϊһλ����������������
*/

class Solution {
public:
    void add(int &addsum)
    {
        int temp = 0;
        while(addsum > 0)
        {
            temp += (addsum % 10);
            addsum /= 10;
        }
        addsum = temp;
    }
    int addDigits(int num) {
        int addnum = num;
        while(addnum >= 10)
        {
            add(addnum);
        }
        return addnum;
    }
};


int main()
{
    int a =  1119;
    Solution s;
    a= s.addDigits(a);
    cout << a << endl;
    system("pause");
}