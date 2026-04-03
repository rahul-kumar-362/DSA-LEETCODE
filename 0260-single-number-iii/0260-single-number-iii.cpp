class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long XORR=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            XORR^=nums[i];                   
        }
        //PEHLE SABKA XORR LELIYA
        int b1=0;
        int b2=0;
        //Duplicates cancel aur 2 numbers ka Xor AAgaya

        for(int i=0;i<n;i++){
            //int rightmostBit=(XORR&(XORR-1))^XORR;
            int rightmostBit=XORR & (-XORR);
            //SINCE THIS WILL GIVE YOU THE RIGHTMOST BIT


            if(nums[i]&rightmostBit){
                //Ha toh b1
                b1=b1^nums[i];
            }
            else{
                b2^=nums[i];
            }
        }

        return {b1,b2};
    }
};