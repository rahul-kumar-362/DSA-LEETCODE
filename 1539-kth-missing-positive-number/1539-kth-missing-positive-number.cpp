class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int n = nums.size();

        int st = 0;
        int end = n-1;

        while(st<=end){
            int mid = st + (end - st)/2;
            int missingNo = (nums[mid]-(mid+1));

            if(missingNo < k){//toh answer right mai...
                st = mid + 1;
            }
            else{
                end = mid - 1 ;
            }
        }
        return st + k;
    }
};