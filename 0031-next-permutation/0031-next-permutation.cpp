class Solution {
public:


    //Optimal APPROACH ...


    
    //T.C. - O(N)
    //S.C. - O(1)


    void nextPermutation(vector<int>& nums) {

        int n=nums.size();

        int idx=-1;//kept index 



        //STEP 1 :  TO FIND THE IDX  OR BREAKPOINT/DIP 
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){//agar decreasing sort order break kiya toh
                idx=i;//got idx
                break;
            }
        }

        if(idx==-1){//iska matlab reverse sorted hai array
        //therefore,ans will be sorted sequence 
            reverse(nums.begin(),nums.end());
            return;
        }

        //STEP 2 : NOW to swap with the smallest one but greater than idx

        for(int i=n-1;i>=idx;i--){
            if(nums[i]>nums[idx]){
                swap(nums[i],nums[idx]);
                break;
            }
        }

        //STEP 3 : Hence got the first corrected sequence now WANT other Sorted sequence for the MINIMUM

        //therefore


        reverse(nums.begin()+idx+1,nums.end());

    }
};