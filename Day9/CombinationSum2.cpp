#include<bits/stdc++.h>
void func(int i, int target, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans) {
    if(target == 0) {
        ans.push_back(ds);
        return;
    }
    
    for(int j = i; j < nums.size(); j++) {
        if(j > i && nums[j] == nums[j-1]) continue;
        if(nums[j] <= target) {
            ds.push_back(nums[j]);
            func(j+1, target-nums[j], nums, ds, ans);
            ds.pop_back();
        }
    }
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	sort(arr.begin(), arr.end());
    vector<int> ds;
    vector<vector<int>> ans;
    func(0, target, arr, ds, ans);
    return ans;
}
