#include<iostream>
using namespace std;
#include<vector>

template<typename T>
void sele_sort(vector<T> &arr){
    int len = arr.size();
    for(int i =0; i<len;++i){
        int min = arr[i];
        int index = i;
        for(int j = i+1;j<len; ++j){
            if(min > arr[j]){
                min = arr[j];
                index = j;
            }
        }
        swap(arr[i],arr[index]);
    }
}

int main(){
    vector<int> arr = {1,4,2,3,5,6,1,0};
    sele_sort(arr);
    for(int a : arr){
        cout << a << " " ;
    }
    cout << endl;
    for(vector<int>::iterator it = arr.begin(); it!=arr.end(); ++it){
        cout << *it << " " ;
     }
    return 0;
}