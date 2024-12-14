#include<iostream>
using namespace std;
#include<vector>

/*
��������� ��һ������ ��ָ����������һ���ֵ����������С�
����ʽ�أ����������������и������ֵ�˳���С����������һ�������У���ô�����
 ��һ������ �������������������������������Ǹ����С�
�����������һ����������У���ô��������������Ϊ�ֵ�����С�����У�������Ԫ�ذ��������У���
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int i = 0;
        for(int j = len-1;j>0;j--){ //�ҵ���һ�������ǰ������
            if(nums[j]>nums[j-1]){
                i = j;break;
            }
        }
        if(i == 0){
            for(int l=i,r=len-1;l<r;l++,r--){
                int temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;
        }
        return;
        }
        for(int j = len-1;j>i-1;j--){//�Ӻ���ǰ�ҵ�һ������nums[i-1]������
            if(nums[j]>nums[i-1]){
                int temp = nums[i-1];
                nums[i-1] = nums[j];
                nums[j] = temp;
                break;
            }
        }
        for(int l=i,r=len-1;l<r;l++,r--){
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
        }
        return;
    }
};

int main(){
    Solution s;
    vector<int> v1 = {3,2,1};
    s.nextPermutation(v1);
}