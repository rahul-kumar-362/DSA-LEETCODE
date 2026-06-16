class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //BETTER APPROACH USING HASHING


        int n=nums.size();
        set<vector<int>>uniQuetriplets;
       // sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

                set<long long >s;
                for(int k=j+1;k<n;k++){
                    long long fourth = 1LL*target - nums[i] - nums[j] - nums[k];

                    if(s.count(fourth)){//agar mil gaya
                        //store answer

                        vector<int>temp = {nums[i],nums[j],nums[k],(int)fourth};
                        sort(temp.begin(),temp.end());
                        uniQuetriplets.insert(temp);
                    }

                    s.insert(nums[k]);
                }
            }
        }
        return vector<vector<int>>(uniQuetriplets.begin(),uniQuetriplets.end());
    }
};