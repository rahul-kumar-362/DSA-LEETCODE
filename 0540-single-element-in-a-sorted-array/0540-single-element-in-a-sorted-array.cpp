class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //OH wow .... first they taken mid at the even position then check
        int n = nums.size();
        int st = 0;
        int end = n-1;
        while(st<end){
            int mid = st+(end - st)/2;
            //FIRST take mid to even position

            if(mid%2==1)mid--;

            //NOW CHECK FOR MID+1
            if(nums[mid]==nums[mid+1]){//pair hai
                st = mid+2;
            }

            //ya fir ans...
            else{
                end = mid;//YAANI ANSWER PEHLE HAI BAADME NAHI 
            }
        }
        return nums[end];// BECAUSE AFTER LOOP ST == END
    }
};