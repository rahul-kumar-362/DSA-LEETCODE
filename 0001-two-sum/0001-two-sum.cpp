class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int>mpp;
    vector<int>ans;
    for(int i=0;i<nums.size();i++){

        int complement=target-nums[i];
        if(mpp.count(complement)){;//agar map mai complement exist toh bahar
            ans={mpp[complement],i};
        }
        mpp[nums[i]]=i;//map mai val,idx store
    }

        return ans;
    }
};

