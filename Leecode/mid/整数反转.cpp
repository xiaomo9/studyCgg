#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<math.h>
/*
����һ�� 32 λ���з������� x �����ؽ� x �е����ֲ��ַ�ת��Ľ����

�����ת���������� 32 λ���з��������ķ�Χ [?2^31,  2^31 ? 1] ���ͷ��� 0��

���軷��������洢 64 λ�������з��Ż��޷��ţ���
 
*/

class Solution {
public:
    int reverse(int x) {
        vector<int> arr;
        bool flag = false;
        if(x<0) flag = true;
        x = abs(x);
        while (x!=0)
        {
            int unit = x %10;
            x /= 10;
            arr.push_back(unit);
        }
        int result = 0;
        int arry = arr.size()-1;
        for(int a : arr){
            result += a*pow(10,arry);
            if(result>(pow(2,31)-1)||result<pow(-2,31)) return 0;
            arry--;
        }
        if(flag) result = -result;
        return result;
    }
};


int main(){
    Solution s;
    int a = -321;
    int b = s.reverse(a);
    cout << b << endl;
    system("pause");
    return 0;
}