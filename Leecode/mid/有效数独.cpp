#include<iostream>
using namespace std;
#include<vector>

/*
��Ч������������������������

ͬһ��������ÿһ��ֻ�ܳ���һ�Σ�

ͬһ��������ÿһ��ֻ�ܳ���һ�Σ�

ͬһ��������ÿһ��С�Ź���ֻ�ܳ���һ�Ρ�
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9]={0},coluum[9][9]={0},subboxs[3][3][9]={0}; //�����С��С��Ź������飬������¼ÿ��ֵ���ֵĴ���
        for(int i = 0;i<9;i++){//������
            for(int j = 0;j<9;j++){//������
                if(board[i][j]!='.'){
                    int num = board[i][j] - '0' - 1;
                    rows[i][num]++;
                    coluum[j][num]++;
                    subboxs[i/3][j/3][num]++;
                    if(rows[i][num]>1||coluum[j][num]>1||subboxs[i/3][j/3][num]>1) return false;
            }}
        }
        return 1;
    }
};