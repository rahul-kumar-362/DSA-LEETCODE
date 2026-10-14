class Solution {
public:

//BC ... SIMILAR to the Smallest Divisor Question ...WTF
    int minEatingSpeed(vector<int>& piles, int h) {
        //Binary Search.... N(log M) where M is highest in piles array

        int lo = 1;
        int hi = *max_element(piles.begin(),piles.end());

        while(lo<=hi){
            int mid = lo + (hi - lo)/2;
            long long sum = 0;
            for(int i = 0 ; i < piles.size() ; i++){
               sum += (1LL*piles[i] + mid - 1 )/mid;//ceil(piles[i]/mid)
            }

            if(sum <= h){//valid toh aur chhota dhundo...
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return lo;
    }
};