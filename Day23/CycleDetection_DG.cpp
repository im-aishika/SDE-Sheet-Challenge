/* The below code is the cycle detection in a directed graph using DFS traversal algorithm  */

#include<bits/stdc++.h>
bool cycleDFS(int node, vector<int> &vis, vector<int> &pathVis, vector<int> adj[]) {
    vis[node] = 1;
    pathVis[node] = 1;
    
    for(auto it: adj[node]) {
        if(vis[it] == 0) {
            if(cycleDFS(it, vis, pathVis, adj)) {
                return true;
            }            
        }
        else if(vis[it] == 1 && pathVis[it] == 1) {
             return true;
         }
    }
    pathVis[node] = 0;
    return false;
}
int detectCycleInDirectedGraph(int V, vector <pair<int, int>> & edges) {
  // Write your code here.
    vector<int> vis(V+1, 0);
    vector<int> pathVis(V+1, 0);
    vector<int> adj[V+1];
    
    for(int i = 0; i < edges.size(); i++) {
        adj[edges[i].first].push_back(edges[i].second);
    }
    
    for(int i = 1; i <= V; i++) {
        if(vis[i] == 0) {
            if(cycleDFS(i, vis, pathVis, adj)) {
                return true;
            }
        }
    }
    return false;
}
