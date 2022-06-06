//Approach 1: TLE in CodeStudio -> passes 10/11 test cases

#include<bits/stdc++.h>
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	
    int i = 0;
    while(i < m) {
        if(arr1[i] > arr2[0]) {
            swap(arr1[i], arr2[0]);
            if(arr2[0] > arr2[1]) sort(arr2.begin(), arr2.end());
        }
        i++;
    }    
    int j = 0;
    for(int i = m; j < n; i++) {
        arr1[i] = arr2[j++];
    }
    return arr1;
}

//Approach 2: GAP METHOD -> passes all test cases 11/11

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {    
    /* insert the elements of arr2 at the end of arr1 */
    for(int i = m, j = 0; j < n; i++) {
        arr1[i] = arr2[j++];
    }  
    
    int g = ceil((float)(m+n)/2);
    
    while(g > 0) {
        int i = 0;
        int j = g;
        while(j < (m + n)) {                   
            if(arr1[i] > arr1[j]) {
                swap(arr1[i], arr1[j]);
            }
            i++;
            j++;
        }
        
        if(g == 1) {
            g = 0;
        }
        else {
            g = ceil((float) g / 2);
        }
    }
    return arr1; 
}
