#include<iostream>
using namespace std;


void quick_sort(int arr[], int low, int high){
    if(low>=high) return;
    int l = low, r = high;
    int pivot = arr[low];
    while(low < high){
        while(low< high && arr[high] >= pivot){
            high --;
        }
        arr[low] = arr[high];
        while(low < high && arr[low] <= pivot){
            low ++;
        }
        arr[high] = arr[low]; 
    }
    arr[low] = pivot;
    quick_sort(arr,l,low-1);
    quick_sort(arr,low+1,r);
}


int main(){
    int arr[5] = {2,1,4,8,7};
    quick_sort(arr,0,4);
    for(int a : arr){
        cout << a << " ";
    }
    return 0;
}