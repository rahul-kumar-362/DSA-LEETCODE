class Solution {//GPT CODE
public:
    void dfs(TreeNode* root, string path, vector<string>& res) {
        if(!root) return;

        if(!root->left && !root->right) {
            res.push_back(path + to_string(root->val));
            return;
        }

        path += to_string(root->val) + "->";
        dfs(root->left, path, res);
        dfs(root->right, path, res);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root, "", res);
        return res;
    }
};
