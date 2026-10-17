class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        //I CAN TRY TO FIND 2 INDEXES BETWEEN WHICH ANSWER LIES...
        int n = nums.size();

        //MY BINARY SEARCH
        int st = 0;
        int end = n-1;

        int F = -1;//first
        int L = -1;//last
        int missingNo = -1;
        while(st<=end){
            int mid = st + (end - st)/2;

            if((nums[mid]-(mid+1))<k){//toh answer right mai...
                st = mid + 1;
                F = nums[mid];//yahi hoga last mai F index
                missingNo = nums[mid]-(mid+1);
            }
            else{
                end = mid - 1 ;
                L =nums[mid];
            }
        }
        // //F aur L toh milgye
        // cout<<F<<" "<<L; 


        //AGAR baadme hoga toh EASY
        if(L==-1)return nums[n-1] + (k-missingNo);

        else{//answer LIE IN BETWEEN
            return F+(k-missingNo) ;//for answer
        }
        return -1;
    }
};