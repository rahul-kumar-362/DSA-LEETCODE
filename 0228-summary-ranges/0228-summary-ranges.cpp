class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        int n=nums.size();
        if(nums.size()==0){
            return {};
        }
        if(nums.size()==1){
            return {to_string(nums[0])};
        }
        vector<string>ans;


        for(int i=0;i<nums.size();i++){
            int first=nums[i];
            int firstidx=i;
          //  string temp=to_string(nums[i]);
            while(i<n-1 && nums[i+1]==nums[i]+1){
                i++;
            }
            if(firstidx==i){
                ans.push_back(to_string(first));
            }
            else{
                ans.push_back(to_string(first)+"->"+to_string(nums[i]));
            }
            //firstidx=i;
            first=nums[i];

        }
        return ans;
    }
};