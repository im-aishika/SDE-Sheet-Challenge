#include<bits/stdc++.h>

struct meeting {
    int startTime;
    int finishTime;
    int ind;
};

bool comp (struct meeting a, struct meeting b) {
    if(a.finishTime < b.finishTime) return true;
    if(a.finishTime > b.finishTime) return false;
    if(a.finishTime == b.finishTime) {
        if(a.ind < b.ind) return true;
    }
    return false;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();
    struct meeting meet[n];
    for(int i = 0; i < n; i++) {
        meet[i].startTime = start[i];
        meet[i].finishTime = end[i];
        meet[i].ind = i+1;
    }
    
    sort(meet, meet + n, comp);
    
    vector<int> ans;
    int prevFt = -1;
    
    for(int i = 0; i < n; i++) {
        int st = meet[i].startTime;
        int ft = meet[i].finishTime;
        int ind = meet[i].ind;
        
        if(prevFt < st) {
            prevFt = ft;
            ans.push_back(ind);
        }
    }
    return ans;
}
