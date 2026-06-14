class Solution {
public:




    //permutation means just rearrangement and not like subsequences

    //so

    //
    void func( vector<int>&nums,vector<vector<int>>&ans,vector<int>temp,vector<int>used){

        int n=nums.size();
        //base case 
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }


        for(int i=0;i<n;i++){

            //already used ...
            if(used[i])continue;

            // choose
            used[i] = 1;
            temp.push_back(nums[i]);

            func(nums,ans, temp, used);

            // backtrack
            temp.pop_back();
            used[i] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int> temp;
        vector<int> used(nums.size(), 0);

        func(nums, ans,temp, used);

        return ans;
    }
};