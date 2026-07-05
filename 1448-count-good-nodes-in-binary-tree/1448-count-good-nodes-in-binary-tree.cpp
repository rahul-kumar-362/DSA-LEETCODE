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
public: //OPTIMAL SOLUTION...   

//✅ Time: O(n) (Optimal)
//✅ Space: O(h) (Optimal)

    void solve(TreeNode*root,int maxsoFar,int &count){

        if(root==NULL)return;

        if( maxsoFar<=root->val)count++;
        
        maxsoFar=max(maxsoFar,root->val);//max track sabke liye
        solve(root->left,maxsoFar,count);
        solve(root->right,maxsoFar,count);
    }
    int goodNodes(TreeNode* root) {
        //mujhse bada koi nai hona chahiye
        int maxsoFar=INT_MIN;
        int count=0;
        solve(root,maxsoFar,count);
        return count;
    }
};