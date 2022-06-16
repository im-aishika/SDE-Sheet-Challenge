#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    unordered_map<int,int> mpp;
    //putting all the elements inside the hashmap
    for(int i = 0; i < n; i++) {
        mpp[arr[i]] ++;
    }
    
    //iterate over the hashmap and find the longest consecutive subsequence
    int maxi = 0;
    int cnt = 0;
    for(auto it: mpp) {
        if(mpp.find(it.first-1) == mpp.end()) {
            cnt = 0;
            int x = it.first;
            while(mpp.find(x) != mpp.end()){
                cnt ++;
                x = x + 1;
            }
        }
        maxi = max(maxi, cnt);
    }
    return maxi;
}
