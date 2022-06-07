//Approach 1: Dynamic programming -> Memoization
//Time Complexity: O(M*N)
//Space Complexity: O((M-1)+(N-1)) + O(M*N) [recursion stack space and size of DP table respectively]

#include <bits/stdc++.h> 
int countPaths(int i, int j, vector<vector<int>> &dp) {
    //out of bound cases
    if(i < 0 || j < 0) return 0;
    //base case
    if(i == 0 && j == 0) {
        return 1;
    }
    //check if previously calculated, directly return from dp table
    if(dp[i][j] != -1) return dp[i][j];
    
    int up = countPaths(i-1, j, dp);
    int lf = countPaths(i, j-1, dp);
    return dp[i][j] = (up + lf);
}

int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n, -1));
    return countPaths(m-1, n-1, dp);
}

/********************************************************************************************************************************************/

//Approach 2: Dynamic Programming -> Tabulation
//Time Complexity: O(M*N)
//Space Complexity: O(M*N) [size of DP table]

#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	int dp[m][n];
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0) {
                dp[i][j] = 1;
            }
            else {
                int up = 0, lf = 0;
                if(i > 0) up = dp[i-1][j];
                if(j > 0) lf = dp[i][j-1];
                dp[i][j] = (up + lf);
            }
        }
    }
    return dp[m-1][n-1];
}

/*********************************************************************************************************************************************/

//Approach 3: Using combinators

#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
    //the given grid has m rows and n columns. So to reach the destination
    //from start (0,0) to destination (m-1, n-1); we have to take (m-1)
    //down turns and (n-1) right turns.
    
    //Total path length = (m-1) + (n-1) = (m+n-2)
    //Out of the total path length, I just need to
    //choose my (m-1) down turns OR (n-1) right turns
    
    //For a 2*3 grid, to go from (0,0) to (1,2),
    //my path length = 2+3-2 = 3
    //down turns = (2-1) = 1 down turn
    //right turns = (3-1) = 2 right turns
    
    //So the problem boils down to (m+n-2) C (m-1) or (m+n-2) C (n-1)
    
    int N = m + n - 2;
    int r = m - 1;
    double res = 1;
    
    for(int i = 1; i <= r; i++){
        res = res * (N - r + i)/i;
    }
    return res;        
}
