class Solution {
public:
    int climbStairs(int n) {
        
        //striver GuruJI ... 

        if(n==0 || n==1)return 1;//kyuki waha par 1 hi way possible hoga


        //if You'll JUMP 1 index  cS(i-1)

        //if you'LL jump 2 stairs  cS(i-2)



        //AREY BHAI .. that is JUST a Fibbonacci


        //therefore

        int prev2=1;
        int prev1=1;
        for(int i=2;i<=n;i++){

            int current=prev1+prev2;
            prev2=prev1;
            prev1=current;
        }
        return prev1;


    }
};