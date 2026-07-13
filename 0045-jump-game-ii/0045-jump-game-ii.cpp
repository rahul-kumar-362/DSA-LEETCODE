// MEMOIZATION (Top-Down DP)

// IDEA:
// solve(i) = Minimum jumps required to reach the last index
// starting from index i.
//
// From the current index, try all possible jumps and take
// the minimum among them.

// Recurrence:
// solve(i) = 1 + min( solve(i+1), solve(i+2), ... , solve(i+nums[i]) )

// Base Case:
// If we are already at the last index,
// then 0 more jumps are required.

// Time Complexity:
// O(n²)
// Each index is computed only once, and from each index we
// may try at most O(n) possible jumps.

// Space Complexity:
// O(n)
// O(n) DP array + O(n) recursion stack.

class Solution {
public:

    int solve(vector<int>& nums, int i, vector<int>& dp) {

        // Reached the last index
        if(i == nums.size() - 1)
            return 0;

        // Already computed
        if(dp[i] != -1)
            return dp[i];

        int ans = INT_MAX;

        int end = min(i + nums[i], (int)nums.size() - 1);

        // Try every possible jump
        for(int j = i + 1; j <= end; j++) {

            int temp = solve(nums, j, dp);

            if(temp != INT_MAX)
                ans = min(ans, 1 + temp);
        }

        return dp[i] = ans;
    }

    int jump(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n, -1);

        return solve(nums, 0, dp);
    }
};