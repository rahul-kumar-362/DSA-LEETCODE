class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //complete brute force approach //Approx T.C. - O(n^4)


        sort(nums.begin(),nums.end());
        
        set<vector<int>>s;
        int n=nums.size();
        for(int i=0;i<n;i++){
    if(i>0 && nums[i]==nums[i-1]) continue;

    for(int j=i+1;j<n;j++){
        if(j>i+1 && nums[j]==nums[j-1]) continue;

        for(int k=j+1;k<n;k++){
            if(k>j+1 && nums[k]==nums[k-1]) continue;

            for(int l=k+1;l<n;l++){
                if(l>k+1 && nums[l]==nums[l-1]) continue;

                long long sum = 1LL*nums[i] + nums[j] + nums[k] + nums[l];

                if(sum == target){
                    s.insert({nums[i], nums[j], nums[k], nums[l]});
                }
            }
        }
    }
}
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
};