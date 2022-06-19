//Time Complexity: O(2^N)
//Space Complexity: O(2^N)

#include<bits/stdc++.h>
void func(int i, int target, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans) {
    if(i == nums.size()) {
        if(target == 0) {
            ans.push_back(ds);
        }
        return;
    }
    
    ds.push_back(nums[i]);
    func(i+1, target-nums[i], nums, ds, ans);
    ds.pop_back();
    func(i+1, target, nums, ds, ans);
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> &nums, int n, int k)
{
    vector<int> ds;
    vector<vector<int>> ans;
    func(0, k, nums, ds, ans);
    return ans;
}
