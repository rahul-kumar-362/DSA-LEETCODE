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
   
    TreeNode* solve(TreeNode*root,TreeNode* p, TreeNode* q){ //OPTIMAL...T.C.->O(N)

        if(root == NULL)return NULL;

        if(root ==p || root ==q)return root;//checking for getting LCA

            TreeNode* left = solve(root->left,p,q);//check for left

            TreeNode* right = solve(root->right,p,q);//check for right
           

            if( left!= NULL && right!=NULL)return root;
            else if(left)return left;
            else if(right)return right;
            return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //jispar dono return wahi lowest parent fir return 


        return solve(root,p,q);
    }
};