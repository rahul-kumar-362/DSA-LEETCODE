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

    TreeNode* buildBST(vector<int>& nums,int st,int end){
        if(st>end)return NULL;
        int mid=st+(end-st)/2; //MIDDLE VALUE LELO 
        //KYUKI USKO ROOT BANANA HAI

        //SINCE INORDER SEQEUCNE IS SORTED TOH MIDDLE MAI VALUE= ROOT


        TreeNode* curr=new TreeNode(nums[mid]);
        curr->left=buildBST(nums,st,mid-1);//repeat for left 
        curr->right=buildBST(nums,mid+1,end);//& right

        return curr;

    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();

        int st=0;
        int end=n-1;
        return buildBST(nums,st,end);

        
        
    }
};