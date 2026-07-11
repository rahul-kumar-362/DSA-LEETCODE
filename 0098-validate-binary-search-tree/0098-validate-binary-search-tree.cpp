class Solution {
public:

    bool solve(TreeNode* root, long long mn, long long mx) {

        if(root == NULL)
            return true;

        if(root->val <= mn || root->val >= mx)
            return false;

        return solve(root->left, mn, root->val) &&
               solve(root->right, root->val, mx);
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};