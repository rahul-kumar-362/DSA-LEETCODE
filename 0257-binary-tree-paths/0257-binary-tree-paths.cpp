class Solution {
public:
    void dfs(TreeNode* root, string &path, vector<string> &ans) {
        if (!root) return;

        int len = path.size();

        path += to_string(root->val);

        if (!root->left && !root->right) {
            ans.push_back(path);
        } else {
            path += "->";
            dfs(root->left, path, ans);
            dfs(root->right, path, ans);
        }

        path.resize(len); // backtrack
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path;
        dfs(root, path, ans);
        return ans;
    }
};