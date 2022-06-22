class Solution {
private:
    void func(TreeNode* node, vector<int> &ans) {
        if(node == NULL) {
            return;
        }
        
        func(node->left, ans);
        func(node->right, ans);
        ans.push_back(node->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        func(root, ans);
        return ans;
    }
};
