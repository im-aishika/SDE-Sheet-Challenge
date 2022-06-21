#include<bits/stdc++.h>

int func(int i, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp) {
    //out of bound case
    if(i < 0) return 0;
    //base case
    if(i == 0) {
        if(wt[i] <= W) return val[i];
        return 0;
    }
    if(dp[i][W] != -1) return dp[i][W];
    //at every index the thief has the option of either stealing or
    //not stealing the particular item
    //case 1: not steal
    int notSteal = 0 + func(i-1, W, wt, val, dp);
    //case 2: steal
    int steal = 0;
    if(wt[i] <= W) {
        steal = val[i] + func(i-1, W-wt[i], wt, val, dp);
    }
    return dp[i][W] = max(steal, notSteal);
}

int maxProfit(vector<int> &val, vector<int> &wt, int n, int W)
{
	  vector<vector<int>> dp(n, vector<int>(W+1, -1));
    return func(n-1, W, wt, val, dp);
}
