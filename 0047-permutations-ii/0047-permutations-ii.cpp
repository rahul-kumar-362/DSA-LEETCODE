class Solution {
public:

    void solve(vector<int>& nums ,vector<int>&temp,vector<vector<int>>&ans,vector<int>&freq){
        int n=nums.size();
        if(temp.size()==n){
            ans.push_back(temp);
            return ;
        }

        for(int i=0;i<n;i++){

            if(i>0 && nums[i-1]==nums[i] && !freq[i-1])continue;//AGAR prev use nahi hua hai aur equal hai toh kaam ka nahi

            if(!freq[i]){//freq nahi hai toh
                temp.push_back(nums[i]);//push
                freq[i]=1;
                
                solve(nums,temp,ans,freq);
            //after backtracking
                freq[i]=0;
                temp.pop_back();
            }
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        vector<int>freq(nums.size());//to get permutation should not repeat


        //AND FOR NOT DUPLICATE WILL SORT AND FIX DUPLICATES
        sort(nums.begin(),nums.end());


        solve(nums,temp,ans,freq);
        return ans;
    }
};