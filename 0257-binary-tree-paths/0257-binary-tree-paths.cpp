class Solution {
public:
    void dfs(TreeNode* root, string &path, vector<string> &ans) {
        if (!root) return;

        // Kitne characters add karne wale hain?
        string curr = to_string(root->val);

        // Node ki value add karo
        path += curr;

        // Leaf
        if (!root->left && !root->right) {
            ans.push_back(path);
        }
        else {
            // Arrow add karo
            path += "->";

            dfs(root->left, path, ans);
            dfs(root->right, path, ans);

            // Arrow hata do
            path.pop_back(); // >
            path.pop_back(); // -
        }

        // Node ki value hata do
        for (int i = 0; i < curr.size(); i++)
            path.pop_back(); 


//🤣🤣 Haan bhai, string ko vector<char> ki tarah hi treat kar sakte ho kai operations me.

// Bahut logon ko ye late pata chalta hai. 😂
   }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path;
        dfs(root, path, ans);
        return ans;
    }
};