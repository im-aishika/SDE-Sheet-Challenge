/*
the first element of a row is greater than the last element of the previous row (if exists).
*/

#include <bits/stdc++.h> 
#include <vector>
bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    // Write your code here.
    int low = 0;
    int high = (m*n)-1;
    
    while(low <= high) {
        int mid = (low + high) >> 1;
        
        if(mat[mid/n][mid%n] == target) {
            return true;
        }
        else if(mat[mid/n][mid%n] < target) {
            low =  mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return false;
}
