class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> x;
        if (root == NULL)
            return x;
        vector<int> left = inorderTraversal(root->left);
        x.insert(x.end(), left.begin(), left.end());
        x.push_back(root->val);
        vector<int> right = inorderTraversal(root->right);
        x.insert(x.end(), right.begin(), right.end());
        return x;
    }
};
