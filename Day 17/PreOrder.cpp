class Solution {
private:
    void func(TreeNode* node, vector<int> &ans) {
        if(node == NULL) {
            return;
        }
        
        ans.push_back(node->val);
        func(node->left, ans);        
        func(node->right, ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        func(root, ans);
        return ans;
    }
};
