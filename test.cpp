#include <iostream>
using namespace std;
#include<time.h>
#include<vector>
#include<algorithm>
#include<map>

class Solution {
    constexpr static int dx[4] = {0,1,0,-1};
    constexpr static int dy[4] = {-1,0,1,0};
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int sum = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i<n; ++i){
            for(int j =0; j<m; ++j){
                if(grid[i][j]){
                    int ans = 0;
                    for(int k = 0; k < 4; ++k){
                        int tx = j + dx[k];
                        int ty = i + dy[k];
                        if(tx<0 || tx>m ||ty<0|| ty>i || grid[ty][tx]==0)
                        {
                            ans +=1;
                        }
                    }
                    sum += ans;
                }
            }
        }
        return sum;
    }
};

int main()
{
    // int a = 9;
    // char b = (char) ('0' + a);
    Solution S;
    vector<int> v1;
    vector<int> v2;
    v1.push_back(2);
    v1.push_back(4);
    v2.push_back(2);
    v2.push_back(1);
    v2.push_back(3);
    int a = S.findContentChildren(v1,v2);
    cout << a << endl;
    system("pause");
}

