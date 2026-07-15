class Solution {
public:
   
    int deleteAndEarn(vector<int>& nums) {
       //ohh  bc same like ...HOUSE ROBBERS


        int n=nums.size();

        int maxi = *max_element(nums.begin(),nums.end());
        vector<int>values(maxi+1,0);//make values vector

        for(int i=0;i<n;i++){
            values[nums[i]]+=nums[i];
        }
       int prev1 = 0;//dp[i-1]
       int prev2 = 0;//dp[i-2]

        for(auto & i : values){
            int curr = max(prev1,prev2 + i);
            prev2 = prev1;
            prev1 = curr;//current
        }
        return prev1;
    }
};