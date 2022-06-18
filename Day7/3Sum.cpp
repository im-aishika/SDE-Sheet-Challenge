#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for(int i = 0; i < n-1; i ++) {
       int target = K - arr[i];
       int low = i+1;
       int high = n-1;
       while(low < high) {
           int twoSum = arr[low] + arr[high];
           if(twoSum < target) {
              low ++;
           }
           else if(twoSum > target){
              high --;
           }
           else {
              vector<int> t(3);
               t[0] = arr[i];
               t[1] = arr[low];
               t[2] = arr[high];
               ans.push_back(t);
               
               while(low < high && arr[low] == t[1]) low ++;
               while(low < high && arr[high] == t[2]) high --;
           }
       }
       while(i < n-1 && arr[i] == arr[i+1]) i++; 
    }
    return ans;
}
