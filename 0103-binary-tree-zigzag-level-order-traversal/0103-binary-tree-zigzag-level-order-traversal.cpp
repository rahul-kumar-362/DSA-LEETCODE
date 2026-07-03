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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;


        if (root==NULL)return result;
        queue<TreeNode*>Q;
        Q.push(root);
        bool flag=true;

        while(!Q.empty()){
            int size=Q.size();

            vector<int>row(size);//row Q ke size ka

            for(int i=0;i<size;i++){//utni size tak
                TreeNode*node=Q.front();//Queue ka front
                Q.pop();



                //Find position to fill NOde's Value

                int index=flag ? i : size-1-i;
                //AGar flag 1 toh forward traverse 
                //otherwise reverse


                row[index]=node->val;

                if(node->left!=NULL){
                    Q.push(node->left);
                }
                if(node->right!=NULL){
                    Q.push(node->right);
                }
            }

            //After this level
            flag=!flag;//reverse flag after 1 loop

            result.push_back(row);
        }
        return result;
    }
};