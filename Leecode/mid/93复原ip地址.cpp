#include<iostream>
using namespace std;
#include<vector>


/*
��Ч IP ��ַ �������ĸ�������ÿ������λ�� 0 �� 255 ֮����ɣ��Ҳ��ܺ���ǰ�� 0����
����֮���� '.' �ָ���

���磺"0.1.2.201" �� "192.168.1.1" �� ��Ч IP ��ַ��
���� "0.011.255.245"��"192.168.1.312" �� "192.168@1.1" �� ��Ч IP ��ַ��
����һ��ֻ�������ֵ��ַ��� s �����Ա�ʾһ�� IP ��ַ���������п��ܵ���Ч IP ��ַ��
��Щ��ַ����ͨ���� s �в��� '.' ���γɡ��㲻�� ���������ɾ�� s �е��κ����֡�
����԰� �κ� ˳�򷵻ش𰸡�
*/
class Solution {
public:
    vector<string> result;
    vector<string> restoreIpAddresses(string s) {
        backtracking(s,0,0);
        return result;
        }
    void backtracking(string s, int startindex, int pointnum){ //�����㷨
        if(pointnum == 3){
            if(is_vail(s,startindex,s.size()-1)){
                result.push_back(s);
            }   
            return;
        }
        for(int i = startindex;i<s.size()-1;i++){
            if(is_vail(s,startindex,i)){
                s.insert(s.begin()+i+1,'.'); //��ӷָ��.
                pointnum += 1;//������Χ
                backtracking(s,i+2,pointnum);// �ݹ�
                pointnum -= 1;
                s.erase(s.begin()+i+1);
            }
        }
    }

    bool is_vail(string s,int start,int end){//�ж��Ƿ����ip��ַ����
        int sum = 0;
        if(start > end) return false;
        for(int i = start;i <= end;i++){ //����ұ�����
            int num = s[i] - '0';
            if(s[i]<'0' || s[i]>'9') return false;//�������ַ�
            if(s[start] == '0' && start != end) return false; //0���滹������
            sum  = sum*10 + num;
            if(sum > 255) return false; //�������255���Ϸ�
        }
        return true;
    }
};