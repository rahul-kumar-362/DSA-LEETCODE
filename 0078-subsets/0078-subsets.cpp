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
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;

        vector<int>output;

        solve(nums,output,ans,0);
        return ans;
    }
};