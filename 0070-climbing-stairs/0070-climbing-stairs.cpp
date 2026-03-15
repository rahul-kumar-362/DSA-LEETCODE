class Solution {
public:


//     🔥 Rahul (Important Pattern)

// This problem teaches the most important DP pattern in LeetCode:

// DP on Fibonacci

// Same pattern appears in:

// • House Robber
// • Min Cost Climbing Stairs
// • Decode Ways
// • Fibonacci
// • Tribonacci



    //O(2^N)


    int climb(int n, vector<int>& dp)
    {
        if(n < 4) return n;

        if(dp[n] != -1)
            return dp[n];

        int ans1 = climb(n-1, dp);
        int ans2 = climb(n-2, dp);

        dp[n] = ans1 + ans2;

        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return climb(n, dp);
    }
};