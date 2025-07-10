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
    bool is_valid(TreeNode* root, long long max_val, long long min_val){
        if(!root) return true;
        if(root->val >= max_val || root->val <= min_val) return false;
        return is_valid(root->left, min(max_val,(long long)root->val), min_val) && is_valid(root->right, max_val, max(min_val,(long long)root->val));
    }
    bool isValidBST(TreeNode* root) {
        return is_valid(root->left, root->val, LONG_MIN) && is_valid(root->right, LONG_MAX, root->val);
    }
};