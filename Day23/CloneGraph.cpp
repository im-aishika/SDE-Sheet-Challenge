
#include<bits/stdc++.h>
graphNode* DFS(graphNode* node, map<graphNode*, graphNode*> &mpp) {
    graphNode* clone = new graphNode(node->data);
    mpp[node] = clone;   
    
    for(auto it: node->neighbours) {
        if(mpp.find(it) != mpp.end()) {
            clone->neighbours.push_back(mpp[it]);
        }
        else {
            clone->neighbours.push_back(DFS(it, mpp));
        }
    }    
    return clone;
}
graphNode *cloneGraph(graphNode *node)
{
    map<graphNode*, graphNode*> mpp;
    if(node == NULL) {
        return NULL;
    }
    else if(node->neighbours.size() == 0) {
        graphNode* clone = new graphNode(node->data);
        return clone;
    }
    else {
        return DFS(node, mpp);
    }
}
