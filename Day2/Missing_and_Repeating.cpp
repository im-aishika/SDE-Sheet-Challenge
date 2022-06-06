//Approach 1: Using a frequency vector array
//Time Complexity: O(N) + O(N) ~ O(N)
//Space Complexity: O(N+1) ~ O(N)

#include <bits/stdc++.h>
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    //inserting all the elements of the array into the vector and 
    //keeping count of the frequencies
    vector<int> freq(n+1);
    for(int i = 0; i < n; i++) {
        freq[arr[i]] ++;
    }
    
    int mis = 0, rep = 0;
    for(int i = 1; i < n+1; i++) {
        if(freq[i] == 0) mis = i;
        else if(freq[i] == 2) rep = i;
    }
    
    return {mis, rep};
}

//Approach 2: Optimat approach
