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

    void solve(TreeNode*root,priority_queue<int>pq,int &count){

        if(root==NULL)return;
       // priority_queue<int>pq;
       

        if(pq.empty() || pq.top()<=root->val)count++;//agar bada hai pehle se to good node
        pq.push(root->val);
        solve(root->left,pq,count);
        solve(root->right,pq,count);
    }
    int goodNodes(TreeNode* root) {
        //mujhse bada koi nai hona chahiye
        priority_queue<int>pq;
        int count=0;
        solve(root,pq,count);
        return count;
    }
};