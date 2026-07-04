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

    void solve(TreeNode* root, int targetSum,vector<vector<int>>&ans,vector<int>&temp,int tempSum){

        if(root==NULL)return ;
        

        temp.push_back(root->val);//current 
        tempSum+=root->val;

        if(root->right ==NULL && root->left==NULL){//LEAF NODE
            if(targetSum == tempSum)ans.push_back(temp);
            temp.pop_back();//oye yaha toh pop back karde OYE
            return ;
           // temp.clear();
        }



        solve(root->left,targetSum,ans,temp,tempSum);

      
        
        solve(root->right,targetSum,ans,temp,tempSum);

        //tempSum-=temp.back();
        temp.pop_back();//after recursion backtracking
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        //agar leaf node par pocha toh return path
        vector<int>temp;
        vector<vector<int>>ans;
        int tempSum=0;
        if(root ==NULL) return {};
        solve(root,targetSum,ans,temp,tempSum);
        return ans;
    }
};