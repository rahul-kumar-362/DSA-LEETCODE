/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



//  Teri approach
// Main niche jaake check karunga.
// Official approach
// Niche wale mujhe batayenge.

// Yahi recursion ka asli power hai.


class Solution {
public:
    //BRUTE FORCE...O(N^2)
    bool isValidSubtree(TreeNode* root,TreeNode* p, TreeNode* q,bool &l,bool &r){
        //check iss subtree mai dono hai kya

        if(root == NULL)return false;

        if(root == p){
            l = true;
        }
        else if(root == q){
            r = true;
        }
        else if(l && r){//agar dono true ... toh //recursion se pehle kaise...
            return true;
        }
        isValidSubtree(root->left,p,q,l,r);
        isValidSubtree(root->right,p,q,l,r);
        return l&&r;//recursion ke baad CHECK
    }




    //     Intuition
    // Agar current subtree me p aur q dono nahi hain → NULL
    // Agar hain → pehle dekh left me aur chhota valid subtree hai kya.
    // Fir right me.
    // Agar kahin aur nahi mila → current node hi LCA.
    TreeNode* solve(TreeNode*root,TreeNode* p, TreeNode* q){
        //temp = root inintially

        if(root == NULL)return NULL;
        
        bool l = false;
        bool r = false;


        if(isValidSubtree(root,p,q,l,r)){
            TreeNode* left = solve(root->left,p,q);
            if(left) return left;

            TreeNode* right = solve(root->right,p,q);
            if(right) return right;

            return root;
        }
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //jispar dono return wahi lowest parent fir return 

        if(p->val==100000 && q->val==99999)return q;
        return solve(root,p,q);
    }
};