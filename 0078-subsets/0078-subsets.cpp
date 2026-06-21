class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //ANOTHER OPTIMAL APPROACH IS USING  THE BIT -MANIPULATION

        //Since we know that the indexing will be backwards
        vector<vector<int>>ans;
        int n=nums.size();
        for (int i=0;i<(1<<n);i++){   //2^n tak loop chalaya
            vector<int>temp;
            for(int j=0;j<n;j++){
                if( i  & (1<<j))temp.push_back(nums[j]); //i ke liye har set bit check
            }
            ans.push_back(temp);
        }
        return ans;
    }
};