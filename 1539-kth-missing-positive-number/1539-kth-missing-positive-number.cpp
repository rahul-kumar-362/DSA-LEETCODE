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
        //since nums[n-1]+(k-missingLast) is Answer
        //nums[n-1]+ (k - (nums[n-1]-n));
        //k+n aur last mai st = n
    }
};