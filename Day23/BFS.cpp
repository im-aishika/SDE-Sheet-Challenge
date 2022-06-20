#include<bits/stdc++.h>
vector<int> BFS(int V, vector<pair<int, int>> edges)
{
    vector<int> vis(V, 0);
    vector<int> bfs;
    vector<int> adj[2*V+1];
    
    //forming the adjacency matrix from the edges vector
    for(auto it: edges) {
        adj[it.first].emplace_back(it.second);
        adj[it.second].emplace_back(it.first);
    }
    
    for(int i = 0; i < V; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    
    
    for(int i = 0; i < V; i++) {
        if(vis[i] == 0) {
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            
            while(!q.empty()) {
                int node =  q.front();
                q.pop();
                
                bfs.emplace_back(node);
                for(auto it: adj[node]) {
                    if(vis[it] == 0) {
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
        }
    }
    
    return bfs;
}
