#include<iostream>
using namespace std;
#include<vector>

/*
编写一个程序，通过填充空格来解决数独问题。

数独的解法需 遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示。
*/
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n = board[0].size(); // 得出是n*n的棋盘
        backtracking(board,n);
    }
    bool backtracking(vector<vector<char>>& board,int n){
        for(int i = 0;i<n;i++){// 遍历行
            for(int j =0;j<n;j++){//遍历列
                if(board[i][j] == '.'){ //找到是空格的位置
                    for(char c = '1';c <= '9' ;c++){//向空格尝试插入0-9
                        if(is_vaild(i,j,c,board,n)){ //（i，j）插入c
                            board[i][j] = c;
                            if(backtracking(board,n)) return true; // 找到一组符合要求的即刻返回
                            board[i][j] = '.'; //回溯
                        }
                    }
                    return false;//该位置0-9都不可以插入
                }
            }
        }
        return true; //整个棋盘所有位置都遍历了，不存在空位置
    }

    bool is_vaild(int row,int volum, char num,vector<vector<char>>& board,int n) { //判断在（row,volum）插入num是否符合数独规则
        for(int i = 0;i<n;i++){// 判断列是否符合规则
            if(board[i][volum] == num) return false;
        }
        for(int j = 0;j<n;j++){// 判断行是否符合规则
            if(board[row][j] == num) return false;
        }
        int start_row = row / 3 * 3;
        int start_vol = volum / 3 * 3;
        for(int i = start_row; i<start_row +3; i++){//判断3*3九宫格内是否符合规则
            for(int j = start_vol; j< start_vol +3; j++){
                if(board[i][j] == num) return false;
            }
        }
        return true;
    }
};
