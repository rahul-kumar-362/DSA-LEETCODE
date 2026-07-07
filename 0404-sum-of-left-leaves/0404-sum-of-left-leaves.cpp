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

    void solve(TreeNode*root,int &sum,bool isLeft){
        if(root == NULL) return ;

        //agar leaf-Node reach toh ...
        if(root->left == NULL && root->right ==NULL && isLeft){
            sum+=root->val;
            return ;
        }
        solve(root->left,sum,true);
        solve(root->right,sum,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL)return 0;//empty tree ka sum =0;
        int sum = 0;
        bool isLeft=false;
        solve(root,sum,isLeft);
        return sum;
    }
};