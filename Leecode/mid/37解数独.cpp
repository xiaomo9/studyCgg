#include<iostream>
using namespace std;
#include<vector>

/*
��дһ������ͨ�����ո�������������⡣

�����Ľⷨ�� ��ѭ���¹���

���� 1-9 ��ÿһ��ֻ�ܳ���һ�Ρ�
���� 1-9 ��ÿһ��ֻ�ܳ���һ�Ρ�
���� 1-9 ��ÿһ���Դ�ʵ�߷ָ��� 3x3 ����ֻ�ܳ���һ�Ρ�����ο�ʾ��ͼ��
�������ֿո��������������֣��հ׸��� '.' ��ʾ��
*/
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n = board[0].size(); // �ó���n*n������
        backtracking(board,n);
    }
    bool backtracking(vector<vector<char>>& board,int n){
        for(int i = 0;i<n;i++){// ������
            for(int j =0;j<n;j++){//������
                if(board[i][j] == '.'){ //�ҵ��ǿո��λ��
                    for(char c = '1';c <= '9' ;c++){//��ո��Բ���0-9
                        if(is_vaild(i,j,c,board,n)){ //��i��j������c
                            board[i][j] = c;
                            if(backtracking(board,n)) return true; // �ҵ�һ�����Ҫ��ļ��̷���
                            board[i][j] = '.'; //����
                        }
                    }
                    return false;//��λ��0-9�������Բ���
                }
            }
        }
        return true; //������������λ�ö������ˣ������ڿ�λ��
    }

    bool is_vaild(int row,int volum, char num,vector<vector<char>>& board,int n) { //�ж��ڣ�row,volum������num�Ƿ������������
        for(int i = 0;i<n;i++){// �ж����Ƿ���Ϲ���
            if(board[i][volum] == num) return false;
        }
        for(int j = 0;j<n;j++){// �ж����Ƿ���Ϲ���
            if(board[row][j] == num) return false;
        }
        int start_row = row / 3 * 3;
        int start_vol = volum / 3 * 3;
        for(int i = start_row; i<start_row +3; i++){//�ж�3*3�Ź������Ƿ���Ϲ���
            for(int j = start_vol; j< start_vol +3; j++){
                if(board[i][j] == num) return false;
            }
        }
        return true;
    }
};
