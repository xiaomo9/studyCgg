#include<iostream>
#include<vector>
using namespace std;

// ��ȡ�������
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int profit = 0;
        int minprice = 1e9;
        for(int i = 0; i<prices.size(); i++)
        {
            profit = max(profit, prices[i]-minprice);
            minprice = min(minprice,prices[i]);
        }
        return profit;
    }
};

int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(20);
    v.push_back(1);
    v.push_back(1);
    Solution s;
    int a = s.maxProfit(v);
    cout << "�������Ϊ��" << a << endl;
    system("pause");

}