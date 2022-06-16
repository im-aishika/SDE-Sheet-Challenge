#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector<int> &arr) {
    int n = arr.size();
    int maxlen = 0;
    map<int, int> mpp;
    int sum = 0;
    
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        
        if(sum == 0) {
            maxlen = i+1;
        }
        
        if(mpp.find(sum) != mpp.end()) {
            maxlen = max(maxlen, i - mpp[sum]);
        }
        else {
            mpp[sum] = i;
        }
    }
    return maxlen;
}
