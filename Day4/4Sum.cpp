//CodeStudio -> 4Sum

#include <bits/stdc++.h> 
string fourSum(vector<int> arr, int target, int n) {
     sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++){
            int low = j+1;
            int high = n-1;
            int newTarget = target - (arr[i] + arr[j]);
            while(low < high) {
                if(arr[low] + arr[high] == newTarget) {
                    return "Yes";
                }
                if(arr[low] + arr[high] < newTarget){
                    low ++;
                }
                else {
                    high --;
                }
            }
        }
    }
    return "No";
}

//Leetcode -> 4Sum Problem #18
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n < 4) return {};
        
        vector<vector<int>> ans;
        
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++) {
                int low = j+1;
                int high = n-1;
                long newTar = target - ((long)nums[i] + (long)nums[j]);
                
                while(low < high) {
                    int twoSum = nums[low] + nums[high];
                    
                    if(twoSum < newTar) {
                        low ++;
                    }
                    else if(twoSum > newTar){
                        high --;
                    }
                    else{
                        vector<int> t(4);
                        t[0] = nums[i];
                        t[1] = nums[j];
                        t[2] = nums[low];
                        t[3] = nums[high];
                        ans.push_back(t);
                        
                        
                        while(low < high && nums[low] == t[2]) low++;
                        
                        while(low < high && nums[high] == t[3]) high --;
                    }
                }
                
                while(j < n-1 && nums[j] == nums[j+1]) j++;
            }
            while(i < n-1 && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};
