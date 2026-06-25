class Solution {
public:


    int solve(vector<int>&nums,int goal){//we'll try using all subarrays with sum<=k  since it is possible
        if(goal<0)return 0; //ye likhna padta hai mittar
        int L=0;
        int r=0;
        int currsum=0;
        int count=0;
        int n=nums.size();
        while(r<n){
            currsum+=nums[r];

            while( currsum>goal){//agar bada hua toh
                currsum-=nums[L];
                L++;
            }

            count+= (r-L+1);//adding length that will be all the subarrays lesser than ke liye
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        //OPTIMAL SOLUTION IS OF PREFIX SUM AND HASHING 
        //which is also for subarray sum equals k  :

        //so here we'll furthermore optimise space to O(1) since we are using only binary arrays i.e. 0 & 1


        int  n= nums.size();
        
        return solve(nums,goal)-solve(nums,goal-1);
    }
};