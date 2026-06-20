class Solution {
public:

        void solve(vector<int>&nums,vector<int>output,vector<vector<int>>&ans,int i){
            int n=nums.size();
           // if(i==n)break;
            ans.push_back(output);//Khali toh rahega hi answer mai
            for(int j=i;j<n;j++){

                
                if(j>i && nums[j-1]==nums[j])continue;//skip duplicates

                output.push_back(nums[j]);
                solve(nums,output,ans,j+1);
                output.pop_back();
            }



    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(),nums.end());//for preserving sequence
        vector<vector<int>>ans;
        vector<int>output;
        // sort(nums.begin(),nums.end());
        solve(nums,output,ans,0);

        // set<vector<int>>s(ans.begin(),ans.end());

        // ans.clear();
        // ans=vector<vector<int>>(s.begin(),s.end());//for duplicates

        return ans;
    }
};