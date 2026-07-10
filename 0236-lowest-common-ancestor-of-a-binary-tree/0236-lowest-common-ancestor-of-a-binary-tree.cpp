/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



//  Teri approach
// Main niche jaake check karunga.
// Official approach
// Niche wale mujhe batayenge.

// Yahi recursion ka asli power hai.


class Solution {
public:
   
    //-------------OPTIMAL...T.C.->O(N) & S.C.->O(N)-------------//
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)return NULL;

        if(root ==p || root ==q)return root;//checking for getting LCA

            TreeNode* left = lowestCommonAncestor(root->left,p,q);//check for left

            TreeNode* right = lowestCommonAncestor(root->right,p,q);//check for right
           

            if( left!= NULL && right!=NULL)return root;
            if(left)return left;

            return right;
    }
};