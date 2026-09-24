class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n);
        int p=0;int q=1;
        for(int i=0;i<n;i++)
        {
          if(nums[i]>0 && p<n)//positive
          {
            result[p]=nums[i];
            p+=2;
          }
          else if(nums[i]<0 && q<n)
          {
            result[q]=nums[i];
            q+=2;
          }
        }
        return result;
    }
};