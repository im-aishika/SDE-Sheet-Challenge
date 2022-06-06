#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    //in an array there can at max be 2 majority elements which occurs
    //more than N/3 times
    int n = arr.size();
    int cnt1 = 0, cnt2 = 0;
    int candidate1 = 0, 
        candidate2 = 0;
    
    for(int i = 0; i < n; i++) {
        int it = arr[i];
        if(it == candidate1){
            cnt1 ++;
        }
        else if(it == candidate2) {
            cnt2 ++;
        }
        else if(cnt1 == 0) {
            candidate1 = it;
            cnt1 = 1;
        }
        else if(cnt2 == 0) {
            candidate2 = it;
            cnt2 = 1;
        }
        else {
            cnt1 --;
            cnt2 --;
        }
    }
    
    cnt1 = 0, cnt2 = 0;
    for(auto it: arr) {
        if(it == candidate1) cnt1 ++;
        else if(it == candidate2) cnt2 ++;
    }
    
    vector<int> ans;
   
    if(cnt1 > (floor)(n/3)) ans.push_back(candidate1);
    if(cnt2 > (floor)(n/3)) ans.push_back(candidate2);
    sort(ans.begin(), ans.end());
    return ans;
}
