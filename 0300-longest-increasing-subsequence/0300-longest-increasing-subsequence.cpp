class Solution {
public:
    int lengthOfLIS(vector<int>& nums) { //O(n^2) T.C. 
        int n=nums.size();
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){//past only

                if(nums[j]<nums[i]){//increasing condition
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};