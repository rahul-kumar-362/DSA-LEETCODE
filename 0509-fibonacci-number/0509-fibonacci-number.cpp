class Solution {
public:
    // int fib(int n) {
    //     if(n==1 || n==0){
    //         return n;
    //     }
    //     return fib(n-1)+fib(n-2);
    // }
    //KYA CHHEDA BHOSADI ---baar baar kyu likhrea hai




    int solve(int n,vector<int>&dp){
        if(n==1 || n==0){
            return n;
        }
        if(dp[n]!=-1){ //if already calculated ...
            return dp[n];
        }


        return dp[n]=solve(n-1,dp)+solve(n-2,dp);
    }
    int fib(int n){
        //use memoization
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};