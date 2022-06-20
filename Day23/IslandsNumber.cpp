#include<bits/stdc++.h>

class DSU {
private:
    vector<int> parent;
    vector<int> size;
public:
    DSU(int n) {
        for(int i = 0; i < n; i++) {
            parent.push_back(i);
            size.push_back(1);
        }
    }
    
    int findPar(int node) {
        if(node == parent[node]) {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }
    
    void union_find(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);
        
        if(pu == pv) return;
        
        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

int getTotalIslands(int** arr, int n, int m)
{
    DSU dsu (n*m+1);
    int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
    int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
    int cnt = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 1) {
                int ind1 = (i * m)+ j;
                cnt++;
                
                 for(int dir = 0; dir < 8; dir++) {
                     int newX = i + dx[dir];
                     int newY = j + dy[dir];
                    
                     if(newX >= 0 && newX < n && newY >= 0 && newY < m && arr[newX][newY] == 1) {
                         int ind2 = (newX * m) + newY;
                         if(dsu.findPar(ind1) != dsu.findPar(ind2)) {
                             cnt --;
                             dsu.union_find(ind1, ind2);
                         }
                    }
               }
            }
        }
    }
    return cnt;
}
