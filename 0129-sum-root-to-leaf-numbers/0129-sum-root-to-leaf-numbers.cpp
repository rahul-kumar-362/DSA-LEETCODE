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

    void solve(TreeNode*root,int temp,int &totalSum){

        if(root==NULL)return;

        temp=temp*10+root->val;
        if(root->left==NULL && root->right==NULL){//AAGYA LEAF NODE PAR...
            //temp milgya
            totalSum+=temp;
            return;
        }
       
        solve(root->left,temp,totalSum);
        solve(root->right,temp,totalSum);
    }
    int sumNumbers(TreeNode* root) {
        //saare paths se sum lo aur add karo WTF
        int totalSum=0;
        int temp=0;
        solve(root,0,totalSum);
        return totalSum;
    }
};