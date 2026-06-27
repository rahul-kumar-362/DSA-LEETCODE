class Solution {
public:

    void dfs(vector<vector<int>>& isConnected, vector<int>& vis, int node) {

        vis[node] = 1;

        int n = isConnected.size();

        for(int i = 0; i < n; i++) {
            if(isConnected[node][i] == 1 && !vis[i]) {
                dfs(isConnected, vis, i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector<int> vis(n,0);

        int count = 0;

        for(int i = 0; i < n; i++) {

            if(!vis[i]) {

                count++;

                dfs(isConnected, vis, i);
            }
        }

        return count;
    }
};