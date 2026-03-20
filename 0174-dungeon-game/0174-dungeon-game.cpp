class Solution {
public:

    int stepfunction(int i, int j, vector<vector<int>>& dungeon, vector<vector<int>>& dp){

//         💥 GOLDEN LINE (remember forever)

// “Main yahan enter kar raha hu… future survive karne ke liye kitni health chahiye?”


        int m = dungeon.size();
        int n = dungeon[0].size();

        if(i >= m || j >= n){
            return INT_MAX;
        }

        if(dp[i][j] != -1){   // ⭐ memo check
            return dp[i][j];
        }

        if(i == m-1 && j == n-1){
            if(dungeon[i][j] < 0){
                return dp[i][j] = -dungeon[i][j] + 1;
            }
            else{
                return dp[i][j] = 1;
            }
        }

        int right = stepfunction(i, j+1, dungeon, dp);
        int down  = stepfunction(i+1, j, dungeon, dp);

        int need = min(right, down) - dungeon[i][j];

        return dp[i][j] = max(1, need);   // ⭐ store result
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return stepfunction(0, 0, dungeon, dp);
    }
};