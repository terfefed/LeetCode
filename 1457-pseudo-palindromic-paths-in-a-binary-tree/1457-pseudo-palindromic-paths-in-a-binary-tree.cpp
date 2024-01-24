/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        std::unordered_map<int, int> counts;
        return dfs(root, counts);
    }

private:
    bool isPseudoPalindrome(const std::unordered_map<int, int>& counts) {
        int oddCount = 0;
        for (const auto& entry : counts) {
            if (entry.second % 2 == 1) {
                oddCount++;
            }
            if (oddCount > 1) {
                return false;
            }
        }
        return true;
    }

    int dfs(TreeNode* node, std::unordered_map<int, int>& counts) {
        if (!node) {
            return 0;
        }

        counts[node->val]++;
        int result;
        if (!node->left && !node->right) {
            result = isPseudoPalindrome(counts) ? 1 : 0;
        } else {
            result = dfs(node->left, counts) + dfs(node->right, counts);
        }
        counts[node->val]--;

        return result;
    }
};