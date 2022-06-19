#include<bits/stdc++.h>
void func(int ind, vector<int> &ds, vector<int> &arr, vector<vector<int>> &ans) {
    ans.push_back(ds);
    
    for(int i = ind; i < arr.size(); i++) {
        if(i > ind && arr[i-1] == arr[i]) continue;
        
        ds.push_back(arr[i]);
        func(i+1, ds, arr, ans);
        ds.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr) {
    sort(arr.begin(), arr.end());
    vector<int> ds;
    vector<vector<int>> ans;
    func(0, ds, arr, ans);
    return ans;
}
