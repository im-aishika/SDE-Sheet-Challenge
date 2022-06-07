#include <bits/stdc++.h> 

int merge(int left, int mid, int right, vector<int> &arr, int temp[]) {
    int cnt = 0;
    int i = left;
    int j = mid;
    while(i <= mid-1 && j <= right) {
        if(arr[i] > 2 * arr[j]) {
            cnt += (mid - i);
            j++;
        }
        else {
            i++;
        }
    }
    i =left, j = mid;
    int k = left;
    
    while(i <= mid-1 && j <= right) {
        if(arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }
    
    while(i <= mid-1) {
        temp[k++] = arr[i++];
    }
    
    while(j <= right) {
        temp[k++] = arr[j++];
    }
    
    for(int i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
    return cnt;
}

int mergeSort(int left, int right, vector<int> &arr, int temp[]) {
    int cnt = 0;
    if(left < right) {
        int mid =  (left + right) >> 1;
        
        cnt += mergeSort(left, mid, arr, temp);
        cnt += mergeSort(mid+1, right, arr, temp);
        cnt += merge(left, mid+1, right, arr, temp);
    }
    return cnt;
}
int reversePairs(vector<int> &arr, int n){
	int temp[n];
    return mergeSort(0, arr.size()-1, arr, temp);
}
