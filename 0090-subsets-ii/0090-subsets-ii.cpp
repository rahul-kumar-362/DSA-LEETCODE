class Solution {
public:

        void solve(vector<int>&nums,vector<int>output,vector<vector<int>>&ans,int i){
        int n=nums.size();

        if(i==n){
          ans.push_back(output);
          return ;
        }

        output.push_back(nums[i]);
        solve(nums,output ,ans,i+1);

        output.pop_back();
        solve(nums,output,ans,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(),nums.end());//for preserving sequence
        vector<vector<int>>ans;
        vector<int>output;
        // sort(nums.begin(),nums.end());
        solve(nums,output,ans,0);

        set<vector<int>>s(ans.begin(),ans.end());

        ans.clear();
        ans=vector<vector<int>>(s.begin(),s.end());//for duplicates

        return ans;
    }
};