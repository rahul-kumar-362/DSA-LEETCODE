class Solution {
public:

// 🔥 Golden Pattern (IMPORTANT)
// Whenever:
// "Cannot take adjacent"

// → THINK:
// max(dp[i-1], dp[i-2] + nums[i])



    int robx(vector<int>& nums) {
        
        int prev1 = 0; // dp[i-1]
        int prev2 = 0; // dp[i-2]

        for(int num : nums){
            int curr = max(prev1, prev2 + num);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }


    int rob(vector<int>& nums) {
        
        //DP bolta hai:

// Mujhe future nahi dekhna
// Mujhe best past chahiye
    vector<int>temp1,temp2;
    if(nums.size()==1)return nums[0];
    for(int i=0;i<nums.size();i++){
        if(i!=0)temp1.push_back(nums[i]);
        if(i!=nums.size()-1)temp2.push_back(nums[i]);
    }

    return max(robx(temp1),robx(temp2));
    }
};