/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;

        return isSymmetricHelp(root->left, root->right);
    }

    bool isSymmetricHelp(TreeNode* left, TreeNode* right) {

        // Dono NULL
        if (left == nullptr && right == nullptr)
            return true;

        // Sirf ek NULL
        if (left == nullptr || right == nullptr)
            return false;

        // Values alag
        if (left->val != right->val)
            return false;

        // Mirror check
        return isSymmetricHelp(left->left, right->right) &&
               isSymmetricHelp(left->right, right->left);
    }
};