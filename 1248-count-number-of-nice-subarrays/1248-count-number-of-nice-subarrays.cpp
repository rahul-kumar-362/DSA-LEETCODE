class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        //simple
        int n=nums.size();
        int L=0;
        int aslicount=0;
        int oddcount=0;
        int Lcount=0;//count of valid lefts
       // unordered_map<int,int>mpp;

        for(int r=0;r<n;r++){
           // mpp[nums[r]]++;
            if(nums[r]%2!=0){
                oddcount++;
                Lcount=0;//REinitialise when some odd comes
            }
            while( L<n && oddcount == k){
                Lcount++;
                 if(nums[L]%2!=0){//ODD aaya toh
                    oddcount--;
                }
                // mpp[nums[L]]--;
                L++;
               
               
            }
             aslicount+=Lcount;
        }
        return aslicount;
    }
};