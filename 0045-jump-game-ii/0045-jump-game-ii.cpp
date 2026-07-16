class Solution {
public:

    //MOST OPTIMAL O(N) - GREEDY APPROACH SOLUTION ....
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return 0;
        int jumps = 1;//KYUKI 1 JUMP ALREADY LE CHUKE HAI...
        int L = 1;
        int R = nums[0];
        int temp=0;

        while(R<n-1){
            while(L<=R){  
                temp = max(temp,L+nums[L]);
                L++;
            }
         
            L=R+1;
            //R=nums[R];//aage
            R = temp;
        jumps++; 
        }
        return jumps;
    }
};