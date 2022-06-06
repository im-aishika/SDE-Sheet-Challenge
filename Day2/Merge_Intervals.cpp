#include <bits/stdc++.h> 
/*
    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval
*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    /* sorting the intervals vector in ascending order  */
    sort(intervals.begin(), intervals.end());
    /* the ans vector is used for storing and returning the final answer */
    vector<vector<int>> ans;
    vector<int> t = intervals[0];
    
    for(auto it: intervals) {
        if(it[0] <= t[1]) {
            t[1] =  max(it[1], t[1]);
        }
        else {
            ans.emplace_back(t);
            t = it;
        }
    }
    ans.push_back(t);
    return ans;   
}
