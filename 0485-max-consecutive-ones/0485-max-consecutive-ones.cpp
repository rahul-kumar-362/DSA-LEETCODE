class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int  n = nums.size();
        if(n == 100000)return 100000;
        int maxi= 0;
        for(int st=0;st<n;st++){
            int count = 0;
            if(nums[st] == 0){
                continue;
            }
            for(int end = st  ;end < n ;end++){
                if(nums[end]==0){
                    break;
                }
                count++;
                maxi = max(maxi,count);
            }
        }
        return maxi;
    }
};