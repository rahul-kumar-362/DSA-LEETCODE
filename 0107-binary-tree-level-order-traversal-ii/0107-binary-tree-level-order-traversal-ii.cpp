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
public: //brute force -->reversing the LEVEL ORDER TRAVERSAL
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        if(root==NULL)return {};
        queue<TreeNode*>q;
        q.push(root);
        deque<vector<int>>dq;
        //vector<vector<int>>ans;

        while(!q.empty()){
            vector<int>level;
            int size = q.size();

            for(int i=0;i<size;i++){
                TreeNode*node = q.front();//intitially pointing to the front of queue
                q.pop();

                level.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            dq.push_front(level);
        }
        //reverse(ans.begin(),ans.end());
        vector<vector<int>>ans(dq.begin(),dq.end());
        return ans;
    }
};