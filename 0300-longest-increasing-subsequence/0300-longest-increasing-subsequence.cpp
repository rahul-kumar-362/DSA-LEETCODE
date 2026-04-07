class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        //Yaha par 1 trick use karenge bada hua toh add aur chota hua toh replace
        vector<int>temp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            auto it=lower_bound(temp.begin(),temp.end(),nums[i]);
            //isse bada wala aajayega
            if(it==temp.end()){
                temp.push_back(nums[i]);
            }
            else{
                *it=nums[i];//updated
            }
        }
        return temp.size();
    }
};