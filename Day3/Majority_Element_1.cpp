/*
You have been given an array/list 'ARR' consisting of 'N' integers. 
Your task is to find the majority element in the array. If there is no majority element present, print -1.
*/

#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
	// Write your code here.
    int cnt = 0;
    int candidate = 0;
    
    for(int i = 0; i < n; i++) {
        if(cnt == 0) {
            candidate = arr[i];
        }
        if(candidate == arr[i]) {
            cnt ++;
        }
        else {
            cnt --;
        }
    }
    
    cnt = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == candidate) cnt ++;
    }
    
    return (cnt > n/2) ? candidate: -1;
}
