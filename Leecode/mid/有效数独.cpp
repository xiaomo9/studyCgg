#include<iostream>
using namespace std;
#include<vector>

/*
有效的数独满足以下三个条件：

同一个数字在每一行只能出现一次；

同一个数字在每一列只能出现一次；

同一个数字在每一个小九宫格只能出现一次。
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9]={0},coluum[9][9]={0},subboxs[3][3][9]={0}; //定义行、列、九宫格数组，用来记录每个值出现的次数
        for(int i = 0;i<9;i++){//遍历行
            for(int j = 0;j<9;j++){//遍历列
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