#include <bits/stdc++.h> 

long long merge(long long int start, long long int mid, long long int end, long long *arr, long long temp[]) {
    long long int i = start;
    long long int j = mid;
    long long int k = start;
    long long cnt = 0;
    
    while(i <= mid-1 && j <= end) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            cnt += (mid - i);
            temp[k++] = arr[j++];
        }
    }
    
    while(i <= mid-1) {
        temp[k++] = arr[i++];
    }
    
    while(j <= end) {
        temp[k++] = arr[j++];
    }
    
    for(int i = start; i <= end; i++) {
        arr[i] = temp[i];
    }
    return cnt;
}

long long mergeSort(long long int start,long long int end, long long* arr, long long temp[]) {
    long long cnt = 0;
    if(start < end) {
        long long int mid = (start + end) >> 1;
        
        cnt += mergeSort(start, mid, arr, temp);
        cnt += mergeSort(mid+1, end, arr, temp);
        
        cnt += merge(start, mid+1, end, arr, temp);
    }
    return cnt;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    long long temp[n];
    return mergeSort(0, n-1, arr, temp);
}
