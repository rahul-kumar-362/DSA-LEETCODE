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

    TreeNode* IS(TreeNode*root){//FUNCTION TO FIND inorder successor
        //leftmost value right ki

        while(root->left!=NULL){
            root=root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        //WE HAVE 3 CASES AFTER FINDING THE KEY



        //HERE 
        if(root==NULL)return NULL;

        else if(key<root->val){//toh left mai search
            root->left=deleteNode(root->left,key);
        }
        else if(key>root->val){//toh right mai search
            root->right=deleteNode(root->right,key);
        }
        else{
            //case with where key ==root->val

            //CASE 1: NO child

            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }

            //CASE 2:one CHILD

            if(root->left==NULL || root->right==NULL){//koi 1 NULL toh 
                return root->left==NULL? root->right : root->left;
            }


            //case 3:Two CHild  

            //step : 1.TO FIND inORder Successsor
            //step : 2.TO SWAP it and delete after it

            //MAKE A TEMP NODE 
            TreeNode* temp=IS(root->right);//milgya IS
            root->val=temp->val;
            root->right=deleteNode(root->right,temp->val);
            return root;
        }
        return root;
    }
};