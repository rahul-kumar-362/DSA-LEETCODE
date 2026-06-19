class Solution {
public:

    void solve(int idx,vector<int>&temp,vector<int>& candidates, int target,vector<vector<int>>&ans ){
        int n=candidates.size();
        

        //optimal Approach ...
        if(target==0){  //since we are taking target from some value to 0 
            ans.push_back(temp);
            return;
        }


        for(int i=idx;i<n;i++){
            if(i > idx && candidates[i] == candidates[i-1])continue;//we'll skip All Duplicates...
            if(candidates[i]>target){
                break;//Aamchi jirli ...
            }

            temp.push_back(candidates[i]);
            solve(i+1,temp,candidates,target-candidates[i],ans);//har baar target reduce and index increase
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        //int sum=0;
        vector<int>temp;

        sort(candidates.begin(),candidates.end());
        solve(0,temp,candidates,target,ans);
        return ans;
    }
};