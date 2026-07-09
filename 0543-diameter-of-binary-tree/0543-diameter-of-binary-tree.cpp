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

    //Optimal O(N) T.C 


    pair<int,int>solve(TreeNode*root){//for height and diameter simultaneously...
        if(root == NULL)return make_pair(0,0);//same base case for both ...
        pair<int,int> leftD = solve(root->left);
        pair<int,int> rightD = solve(root->right);
        int currD = leftD.first+rightD.first;//LH+RH 
        int finalD = max(currD,max(leftD.second,rightD.second));

        int finalHeight = max(leftD.first,rightD.first)+1;//for height ...

        return make_pair(finalHeight,finalD);
    }
   
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int>ans = solve(root);
        return ans.second;
    }
};