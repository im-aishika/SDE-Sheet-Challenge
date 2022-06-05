#include<bits/stdc++.h>
bool comp (pair<int, int> f, pair<int, int> s){
    double r1 = (double)(f.second)/ (double)(f.first);
    double r2 = (double)(s.second)/ (double)(s.first);
    return r1 > r2;    
};
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // ITEMS contains {weight, value} pairs.
    //sorting the items vector in decresing order of value
    //so the item at index one has the maximum value
    sort(items.begin(), items.end(), comp);
    
    int i = 0;
    double maxProfit = 0;
    while(w > 0){
        //checking if the weight of item is lesser than the available knapsack capacity
        if(items[i].first <= w){            
            maxProfit += items[i].second;           
        }
        else{            
            maxProfit += (items[i].second / (double)items[i].first) * (double) w;          
        }
        w -= items[i].first;
        i++;      
    }
    return maxProfit;
}
