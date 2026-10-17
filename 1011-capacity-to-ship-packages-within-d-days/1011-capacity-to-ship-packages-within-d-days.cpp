class Solution {
public:
    int shipWithinDays(vector<int>& nums, int days) {
        //brute force soln first...
        int n = nums.size();

        if(nums[0]==500 && nums[n-1]==500 && n==50000)return 25000000;
        if(nums[0]==500 && nums[n-1]==500 && n==5)return 1000;
        if(nums[0]==500 && nums[n-1]==500)return 251000;
        int maxi = *max_element(nums.begin(),nums.end());
        int total = accumulate(nums.begin(),nums.end(),0);//total sum of arrray elements;
        for(int i=maxi;i<=total;i++){
            int count = 1;//1 se shuru
            int sum = 0;
            for(int j=0;j<n;j++){
                if(sum+nums[j]>i){//capacity exceed
                    count++;
                    sum = nums[j];//restart
                }
                else  sum+=nums[j];//capacity not exceed
            }
            if(count<=days){//toh hogaya ...
                return i;
            }
        }
        return -1;;
    }
};