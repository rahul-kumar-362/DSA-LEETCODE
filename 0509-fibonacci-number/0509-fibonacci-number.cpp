class Solution {
public:
    // int fib(int n) {
    //     if(n==1 || n==0){
    //         return n;
    //     }
    //     return fib(n-1)+fib(n-2);
    // }
    //KYA CHHEDA BHOSADI ---baar baar kyu likhrea hai



//T.C and S.C === O(N)

    // int solve(int n,vector<int>&dp){
    //     if(n==1 || n==0){
    //         return n;
    //     }
    //     if(dp[n]!=-1){ //if already calculated ...
    //         return dp[n];
    //     }


    //     return dp[n]=solve(n-1,dp)+solve(n-2,dp);
    // }
    // int fib(int n){
    //     //use Tabulation

    //     if(n==0)return 0;
    //     vector<int>dp(n+1,0);

    //     dp[0]=0;
    //     dp[1]=1;
    //     for(int i=2;i<=n;i++){
    //         dp[i]=dp[i-1] + dp[i-2];
    //     }
    //     return dp[n];
    // }


      int fib(int n){
        //use space Optimization

        if(n==0)return 0;
        int prev2=0;
        int prev1=1;
        int current=prev1+prev2;
        for(int i=2;i<=n;i++){

            current=prev1+prev2;
            prev2=prev1;
            prev1=current;
        }
        return current;
    }
};