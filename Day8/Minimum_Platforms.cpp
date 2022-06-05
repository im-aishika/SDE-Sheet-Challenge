#include<bits/stdc++.h>
int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at, at+ n);
    sort(dt, dt + n);
    
    //i points to the initial arrival time of 2nd element
    int i = 1;
    //j points to the initial destination time of 1st element
    int j = 0;
    int maxi = 1, minPlat = 1;
    
    while(i < n && j < n) {
        if(at[i] <= dt[j]) {
            minPlat ++;
            i++;
        }
        else {
            minPlat --;
            j++;
        }
        
        maxi = max(maxi, minPlat);
    }
    return maxi;
}
