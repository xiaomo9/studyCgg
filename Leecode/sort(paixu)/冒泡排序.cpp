#include<iostream>
using namespace std;
#include<vector>

void maopao(vector<int> &v1){
    int len = v1.size();
    for(int i = 0; i<len-1;++i){
        bool swape = false;
        for(int j = 0;j<len-i-1; ++j){
            if(v1[j] > v1[j+1]){
                int temp = v1[j];
                v1[j] = v1[j+1];
                v1[j+1] = temp;
                swape = true;
            }
            }
        if(!swape){break;}// 一次寻找中，没有交换位置说明已经排好序
    }
}


int main(){
    vector <int> v = {1,5,4,3,7,8,5,9,1};
    maopao(v);
    for (int a : v){
        cout << a<<" ";
    }
    return 0;
}