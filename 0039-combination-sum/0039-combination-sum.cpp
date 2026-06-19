class Solution {
public:

    void solve(int i, int sum,vector<int>&temp,vector<int>& candidates, int target,vector<vector<int>>&ans ){
        int n=candidates.size();
        //pehle try all combinations and wahi print
       

        // if(i==n){
        //     ans.push_back(temp);
        //     return;
        // }
        

        

        if(sum==target){
            ans.push_back(temp);
            return;
        }


        if(i == n || sum > target){ // Base Cases...
            return;
        }


        temp.push_back(candidates[i]);
        sum+=candidates[i];

        solve(i,sum,temp,candidates,target,ans);//pick branch current bhi jabtak ho ske



        sum-=candidates[i];
        temp.pop_back();
        solve(i+1,sum,temp,candidates,target,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        int sum=0;
        vector<int>temp;
        solve(0,sum,temp,candidates,target,ans);
        return ans;
    }
};