class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int n = prices.size();
        //pichle se best lete chalo
        int bestbuy = prices[0];

        for(int i=1;i<n;i++){
            if(prices[i]>bestbuy){//potential
                maxi = max(maxi,prices[i]-bestbuy);
            }
            bestbuy = min(bestbuy,prices[i]); //minimum leke ghumte raho
        }
        return maxi;
    }
};