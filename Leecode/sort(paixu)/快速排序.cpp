#include<iostream>
using namespace std;
#include<vector>

int paritit(int arr[], int low, int high){
    int pivot = arr[low];
    while(low<high){
        while(low<high&&arr[high]>=pivot){
            high --;
        }
        arr[low] = arr[high];//从右向左找到比基点小的数，放在左边
        while (low<high&&arr[low]<=pivot){
            low++;
        }
        arr[high] = arr[low];//从左向右找到比基点大的数，放在右边
    }
    arr[low] = pivot; //左右交汇的地就是中间基点的位置
    return low;
}

void quick_sort(int arr[],int l, int r){
    if(l >= r) return;
    int mid = paritit(arr,l,r);
    quick_sort(arr,l,mid-1);
    quick_sort(arr,mid+1,r);
}

int main(){
    int arr[10] = {3,4,1,2,7,9,10,2,5,6};
    quick_sort(arr,0,9);
    for(int a : arr){
        cout << a << " ";
    }
    return 0;
}