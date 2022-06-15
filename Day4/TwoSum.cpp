//Pair Sum in CodeStudio 

#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int target){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] + arr[j] == target) {
                vector<int> t(2);
                t[0] = arr[i];
                t[1] = arr[j];
                ans.push_back(t);
            }
        }
    }
    return ans;
}


//Two Sum in Leetcode Problem 1

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(mpp.find(target - nums[i]) == mpp.end()) {
                mpp[nums[i]] = i;
            }
            else {
                ans.push_back(mpp[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
        }
        return {};
    }
};
