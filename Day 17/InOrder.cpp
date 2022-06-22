class Solution {
private:
    void func(TreeNode* node, vector<int> &ans) {
        if(node == NULL) {
            return;
        }
        
        func(node->left, ans);
        ans.push_back(node->val);
        func(node->right, ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        func(root, ans);
        return ans;
    }
};
