class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        //if 4 - 5 then LINEAR line,hence peak on RIGHT
        //ulta toh ULTA...

        int st = 1;//KYUKI ANSWER ISS RANGE MAI CHECK....
        int end = n-2;

        if(n==1)return 0;
        if(nums[0]>nums[1])return 0;
        if(nums[n-1]>nums[n-2])return n-1;

        while(st<=end){
            int mid = st + (end - st)/2;

            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid]>nums[mid-1]){// && nums[mid]<nums[mid2]){
                st = mid+1;
            }
            else{//nums[mid]>nums[mid+1]
                end = mid-1;
            }
        }
        return st;
    }
};