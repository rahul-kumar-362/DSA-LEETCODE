class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //dp approach
        vector<int>arr(amount+1,1e9);//ye vector max se initialise hai
        arr[0]=0;
        for(int i=1;i<amount+1 ; i++){
            for(int j=0;j<coins.size();j++){
                if(coins[j]<=i)
                    arr[i]=min(arr[i],1 + arr[i-coins[j]]);
            }
        }

        if(arr[amount]==1e9)return -1;
        return arr[amount];
    }
};