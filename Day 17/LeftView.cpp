//Aproach 1: Using Left Order Traversal logic

#include<bits/stdc++.h>

//the naiva approach is to solve the problem using the concept of
//level order traversal
vector<int> getLeftView(TreeNode<int> *root)
{
    if(root == NULL) return {};
    
    vector<int> ans;
    
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            TreeNode<int> *node = q.front();
            q.pop();
            
            if(i == 0) {
                ans.push_back(node->data);
            }
            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }
        }
    }
    return ans;
}

/********************************************************************************************************************************************/

//Approach 2: Using PREORDER TRAVERSAL

#include<bits/stdc++.h>

void func(TreeNode<int> *node, int level, vector<int> &ans) {
    if(node == NULL) {
        return;
    }
    if(level == ans.size()) {
        ans.push_back(node->data);
    }
    
    func(node->left, level+1, ans);
    func(node->right,level+1, ans);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    func(root, 0, ans);
    return ans;
}
