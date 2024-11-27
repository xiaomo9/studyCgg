#include<iostream>
using namespace std;
#include<vector>

struct Linklist
{
    int val;
    Linklist *next;
    Linklist(int val){
        this->val = val;
        this->next = NULL;
    }
};

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int cnt = 1;
        int sum = 0;
        int n = colors.size();
        for(int i =1;i<k+colors.size();++i)
        {
            if(colors[i%n]==colors[(i-1)%n]){
                cnt = 1;
                continue;
            }
            cnt ++;
            if(cnt >= k) sum++;
        }
        return sum;
    }
};

int main(){
    system("pause");
    return 0;
}