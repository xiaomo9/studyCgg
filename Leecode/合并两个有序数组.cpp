#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>
class Soulation
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        nums1.resize(m+n);
        for(int i =0 ; i<n; i++)
        {
            nums1[m+i] = nums2[i];
        }
        sort(nums1.begin(),nums1.end());
    }
};


int main()
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(2);
    vector<int> v2;
    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(2);
    Soulation s;
    s.merge(v1,3,v2,3);
    for(int i =0; i<6; i++)
    {
        cout<< v1[i] <<endl;
    }
    system("pause");

}