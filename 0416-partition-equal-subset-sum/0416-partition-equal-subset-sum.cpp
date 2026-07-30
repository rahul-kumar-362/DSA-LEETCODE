class Solution {
public:

    vector<vector<int>> dp; // SINCE I and target both are in changing state ...

    bool solve(int i, int target, int &totalsum, vector<int>& nums) {

        if(target == totalsum/2){ // target mil gaya
            return true;
        }

        if(i == nums.size()) return false;

        if(target > totalsum/2) return false; // pruning

        if(dp[i][target] != -1) return dp[i][target]; // already computed

        bool pick = solve(i+1, target+nums[i], totalsum, nums); // pick
        bool notPick = solve(i+1, target, totalsum, nums);      // not pick

        return dp[i][target] = pick || notPick;
    }

    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int totalsum = 0;

        for(int i=0;i<n;i++){
            totalsum += nums[i];
        }

        if(totalsum % 2){ // ODD walo mai kabhi hoga hi nahi 2
            return false;
        }

        dp.resize(n, vector<int>(totalsum/2 + 1, -1));

        int target = 0;

        return solve(0, target, totalsum, nums);
    }
};