class Solution {
public:

    
    int tribonacci(int n) {
        //similar like fibbonacci was dependent on last 2 -- it is dependent on last 3 
        
        if(n==0)return 0;
        if(n==1 || n==2)return 1;

        
        int prev1=0;
        int prev2=1;
        int prev3=1;

        int curr=0;

        for(int i=3;i<=n;i++){
            curr=prev1+prev2+prev3;

            int temp=prev1;
            prev1=prev2;
            prev2=prev3;
            prev3=curr;
        }




        return curr;
    }
};