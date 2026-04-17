class Solution {
public:
    // int fib(int n) {
    //     if(n==1 || n==0){
    //         return n;
    //     }
    //     return fib(n-1)+fib(n-2);
    // }
    //KYA CHHEDA BHOSADI ---baar baar kyu likhrea hai




    int solve(int n,unordered_map<int,int>&dp){
        if(n==1 || n==0){
            return n;
        }
        if(dp.count(n)){ //if already calculated ...
            return dp[n];
        }


        return dp[n]=solve(n-1,dp)+solve(n-2,dp);
    }
    int fib(int n){
        //use memoization
        unordered_map<int,int>dp;
        return solve(n,dp);
    }
};