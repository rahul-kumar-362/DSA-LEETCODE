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


        //     Lekin...

        // Is question ka aur bhi simple recursion hai.

        // Hum preorder

        // Root
        // Left
        // Right

        // me traverse karenge.

        // Jo deepest node sabse pehle milega wahi leftmost hoga.

        // Isliye sirf

        // if(depth > maxDepth)

        // karna hai.

    void solve(TreeNode*root, int depth,int &maxdepth,int &ans){
        //maxdepth wala hi chahiye na ...
        if(root == NULL) return ;

       // if(maxdepth == 1)

       
            if(depth>maxdepth){ //checking depth wise ...
                maxdepth = depth;
                ans = root->val;
                //return;
            }

        solve(root->left,depth+1,maxdepth,ans);
        solve(root->right,depth+1,maxdepth,ans);
    }


    //     Sabse bada conceptual bug

    // Tu soch raha hai:

    // "Bottom Left Value" = "Left child"

    // Lekin actual hai:

    // "Deepest level ka leftmost node."

    // Ye dono alag cheezein hain.
    int findBottomLeftValue(TreeNode* root) {
        int depth = 0;
        int maxdepth = -1;
        int ans = 0;
      //  bool isLeft = false;

        solve(root,depth,maxdepth,ans);
        return ans;
    }
};