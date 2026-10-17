class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int F = -1;
        int L = -1;
        int st = 0;
        int end = n-1;

        while(st<=end){
            int mid = st + (end - st)/2;//samjho first occurence
            
            if(nums[mid] == target){
                F = mid;//milgya toh left search karo right prune
                end = mid -1;
            }
            else if(target<nums[mid]){
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }

        //AGAR pehle mila hi nahi toh nikal do
        if(F==-1)return {-1,-1};

        //Similarly for last element
        st = F;
        end = n - 1;
        while(st<=end){
            int mid = st+(end -st)/2;
            if(nums[mid] == target){
                L = mid; 
                st = mid + 1;//prune left here
            }
            else if(nums[mid]>target){
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }

        // if(F == 0 && L == 0)return { -1,-1};-- if really both 0  then problem
        return {F,L};
    }
};
