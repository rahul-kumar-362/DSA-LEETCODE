class Solution {
public:



// (nums[j] + i - 1) / i -- INTEGER MAI CEILING ka formula
  

//WHEN to find minimum or maximum , BS onn answers used...

    //1 --> N mai hi answer HONA CHahiye coz usse upar bhi 1

    //toh pattern with [invalid invalid valid valid valid valid]


    int smallestDivisor(vector<int>& nums, int threshold) {
        // 

        int st = 1;
        int end = *max_element(nums.begin(),nums.end());
        int mini = INT_MAX;
       
        while(st<=end){
            int mid = st + (end - st)/2;
            int sum = 0;
            for(int i = 0;i<nums.size();i++){
                sum+=(nums[i] + mid - 1) / mid;//formula for ceiling...
            }
            if(sum<=threshold){//valid...toh reduce
                end = mid - 1;
               // mini = min(mini,mid);//SINCE WANT SMALLEST DIVISOR NOT SMALLEST SUM
            }
            else {//invalid  then  eliminate left side
                st = mid + 1;
            }
        }
        return st;//always ans st
    }
};