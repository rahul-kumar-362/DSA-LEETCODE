class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        //OPTIMAL APPROACH ...


        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){

            int j=i+1;
            int k=n-1;


            if(i>0 && nums[i]==nums[i-1]) continue; //TO HANDLE DUPLICATES for ith place

            while(j<k){
               

                int sum=nums[i]+nums[j]+nums[k]; 
                if(sum>0)k--;//bada hua toh
                else if(sum<0)j++;

                //else if(sum==0){
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;

                    while(j<k && nums[j]==nums[j-1]) j++;//TO HANDLE DUPLICATES for jth place

                }

                
                
            }
        }

        return ans;
    }
};