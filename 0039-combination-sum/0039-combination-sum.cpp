class Solution {
public:


void Combination(int idx, int target,vector<int>&candidates,vector<vector<int>>&ans,vector<int>&arr){




    //BASE_CASE FIRST

    if (idx==candidates.size()){
        return ;
    }

    if(target==0){
        ans.push_back(arr);
        return ;
    }

    //(pick)-(non-pick) Architecture 

    //it will tell you to move to the next index or  not

    //1

    if(candidates[idx] <= target){
        arr.push_back(candidates[idx]);
        Combination(idx,target-candidates[idx],candidates,ans,arr);
        arr.pop_back();
    
    }

    Combination(idx+1,target,candidates,ans,arr);//it is for the pick one maybe to search about the next text to U.



}

//pehle we'll make a brute force approach

//that is we'll try all the possible combinations
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>>ans;
        vector<int>arr;

        Combination(0,target,candidates,ans,arr);

        return ans;

    }
};