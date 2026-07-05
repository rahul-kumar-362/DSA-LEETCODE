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

class Solution {  //GPT 5.5
public:
    void dfs(TreeNode* root, int maxSoFar, int &count) {
        if (root == nullptr)
            return;

        if (root->val >= maxSoFar)
            count++;

        maxSoFar = max(maxSoFar, root->val);

        dfs(root->left, maxSoFar, count);
        dfs(root->right, maxSoFar, count);
    }

    int goodNodes(TreeNode* root) {
        int count = 0;
        dfs(root, root->val, count);
        return count;
    }
};