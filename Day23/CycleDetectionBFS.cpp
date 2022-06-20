#include<bits/stdc++.h>
bool cycleBFS(int s, vector<int> &vis, vector<int> adj[]) {
    vis[s] = 1;
    queue<pair<int, int>> q;
    q.push({s, -1});
    
    while(!q.empty()) {
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        
        for(auto it: adj[node]){
            if(vis[it] == 0) {
                vis[it] = 1;
                q.push({it, node});
            }
            else if(it != par) {
                return true;
            }
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int V, int E)
{
    vector<int> vis(V+1, 0);
    vector<int> adj[2*V+1];
    
    //forming the adjacency matrix from the given 2D vector
    for(int i = 0; i < edges.size(); i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    for(int i = 1; i <= V; i++) {
        if(vis[i] == 0) {
            if(cycleBFS(i, vis, adj)) {
                return "Yes";
            }
        }
    }
    return "No";
}
