/*************************************************************************
 * @File Name: merge_sort.cpp
 * @Description: 
 * @Author: ppq~
 * @Created Time: Sun Apr 13 15:25:10 2025
 ************************************************************************/
#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <memory>
#include <functional>

using namespace std;


void merge(vector<int>& arr, int left, int mid, int right, vector<int>& tmp){
    int i = left;
    int j = mid+1;
    int k = left;
    while(i<=mid && j<=right) {
        if(arr[i] <= arr[j]) {
            tmp[k++] = arr[i++];
        }else {
            tmp[k++] = arr[j++];
        }
    }

    while(i<=mid) tmp[k++] = arr[i++];
    while(j<=right) tmp[k++] = arr[j++];

    for(int i=left; i<=right; i++) {
        arr[i] = tmp[i];
    }
}

void mergeSort(vector<int>& arr,int left, int right, vector<int>& tmp) {
    if(left >= right) return;
    int mid = left + (right-left) / 2;
    mergeSort(arr, left, mid, tmp);
    mergeSort(arr, mid+1,right, tmp);
    if(arr[mid] > arr[mid+1]) {
        merge(arr, left, mid, right, tmp);
    }
}

int division(vector<int>& arr, int low, int hight){
    int pivot = arr[low+(hight-low)/2];
    int i = low-1;
    int j = hight+1;
    while(true){
        do{
            ++i;
        }while(arr[i]<pivot);
        do{
            --j;
        }while(arr[j]>pivot);
        if(i>=j) return j;
        swap(arr[i],arr[j]);
    }
}
void quick_sort(vector<int>& arr, int l, int r) {
    if (l>r) return;
    int mid = division(arr, l ,r);
    quick_sort(arr, l, mid);
    quick_sort(arr, mid+1, r);
}

int main()
{
    vector<int> arr = {12,11,13,5,6,7};
    vector<int> tmp(arr.size());
    quick_sort(arr, 0, arr.size()-1);
    //mergeSort(arr, 0, arr.size()-1, tmp);
    for(int i=0; i<arr.size(); i++) {
        cout<< arr[i] << endl;
    } 
    return 0;
}

