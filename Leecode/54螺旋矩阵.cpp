#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int l=0, r = matrix[0].size(),t = 0,b = matrix.size();
        if(matrix.empty()) return {};

        while(true){
            for(int i = l;i<=r;++i){
                result.emplace_back(matrix[t][i]);
            }
            if(++t > b) break;

            for(int i = t;i<=b; ++i){
                result.emplace_back(matrix[i][r]);
            }
            if(--r < l) break;

            for(int i = r; i>=l; --i){
                result.emplace_back(matrix[b][i]);
            }
            if(--b < t) break;

            for(int i = b;i>=t; --i){
                result.emplace_back(matrix[i][l]);
            }
            if(++l > r) break;
        }

        return result;
    }
};