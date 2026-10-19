class Solution {
public:
    int countSum(vector<int>&nums,int i){
        int n = nums.size();
        int sum = 0;
        int count = 1;
        for(int j=0;j<n;j++){
            if(nums[j]+sum<=i){//LE SAKTA HAI...
                sum+=nums[j];
            }
            else{
                count++;
                sum = nums[j];
            }
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        //Similar to BOOK ALLOCATION
        //INVALID INVALID VALID VALID
        int  n = nums.size();
        // if(k>n)return -1;//NAHI HO SAKTA
        int maxi = *max_element(nums.begin(),nums.end());//kam se kam itna
        int total = accumulate(nums.begin(),nums.end(),0);//max total if k = 1
        
        int st = maxi;
        int end = total;
        while(st<=end){
            int mid = st + (end  - st)/2;
            if(countSum(nums,mid)>k){//INVALID toh right
                st = mid + 1;
            }
            else{
                end = mid - 1;//VALID toh aur sahi dhundo max
            }
        }
        return st;
    }
};