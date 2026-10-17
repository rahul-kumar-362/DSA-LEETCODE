class Solution {
public:
    int findMin(vector<int>& nums) {
        //BC ROTATED HOGA TU APNE gharpe ..tere liye mai ab LAST wale se search karwaunga...
        int n = nums.size();
        int st = 0;
        int end = n - 1;

        while(st<end){//equal nahi ho sakta because unique..
            int mid =st + (end - st)/2;
            if(nums[mid]>nums[end]){//agar last wala isse chhota hai toh right mai answer
                st = mid + 1;
            }
            else{//equal ho hi nhi skta isliye < wali condition...
                //iska matlab left mai answer

                end = mid ;//mid bhi answer HO skta
            }
        }
        return nums[st];//==nums[end]...{since after loop here st = end}
    }
};