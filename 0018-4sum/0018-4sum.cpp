class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //OPTIMAL APPROCH ...

        int n=nums.size();
        vector<vector<int>>ans;
        
        //step 1 :  sort nums 
        sort(nums.begin(),nums.end());


        //step 2 : Fix 2 nums and Other 2 by 2 ptr approach
        for(int i=0;i<n;i++){

            if(i>0 && nums[i] == nums[i-1] )continue;
            for(int j=i+1;j<n;j++){

                if(j>i+1 && nums[j] == nums[j-1] )continue;
                int p=j+1;
                int q=n-1;

                while(p<q){
                    long long sum = 1LL*nums[i]+nums[j]+nums[p]+nums[q];

                    if(sum<target)p++;
                    else if(sum>target)q--;
                    else {//equal ka case
                        ans.push_back({nums[i],nums[j],nums[p],nums[q]});
                        p++;
                        q--;

                        while(p<q && nums[p]==nums[p-1]) p++;
                        while(p<q && nums[q]==nums[q+1]) q--;
                    }
                }
            }
        }
        return ans;
    }
};