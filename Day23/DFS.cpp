#include<bits/stdc++.h>
void dfs(int node, vector<int> &vis, vector<int> &temp, vector<int> adj[]) {
    vis[node] = 1;
    temp.push_back(node);
    
    for(auto it: adj[node]) {
        if(vis[it] == 0) {
            dfs(it, vis, temp, adj);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<int> vis(V, 0);
    vector<int> adj[2*V+1];
    
    for(int i = 0; i < edges.size(); i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    //declaring the answer vector
    vector<vector<int>> ans;
    
    for(int i = 0; i < V; i++) {
        if(vis[i] == 0) {
            vector<int> temp;
            dfs(i, vis, temp, adj);
            ans.push_back(temp);
        }
    }
    return ans;
}
