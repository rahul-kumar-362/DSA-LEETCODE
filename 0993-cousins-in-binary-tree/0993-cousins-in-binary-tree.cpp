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

    //BAAP ka pata sath hi rakho humesha in treenode*parent

    void solve(TreeNode*root,TreeNode*parent,int depth,int x,int y,int &d1,int &d2 ,TreeNode* &p1,TreeNode* &p2){

        if(root == NULL)return ;
        if(root->val == x){
            d1 = depth;
            p1 = parent;
        }
        else if (root->val == y){
            d2 = depth;
            p2 = parent;
        }
        solve(root->left,root,depth+1,x,y,d1,d2,p1,p2);//root hi parent hai uska
        solve(root->right,root,depth+1,x,y,d1,d2,p1,p2);//root hi parent hai uska
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int d1 = -1;
        int d2 = -1;
        int depth = 0;
        TreeNode * parent = NULL; //initialise ...
        TreeNode* p1 = NULL;
        TreeNode* p2 = NULL;
        solve(root,parent,depth,x,y,d1,d2,p1,p2);
        return d1 == d2 && p1!=p2; //since we want COUSINS not SIBLINGS...
    }
};