     
        //💀 FINAL INSIGHT

// Binary search tab lagta hai jab answer space me
// “first true” ya “first valid” find karna ho

//🔥


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long hi=*max_element(piles.begin(),piles.end());

        long long lo=1;
   

// 🧠 Statement kya bolta hai?

// “Agar pile me k se kam bananas hai, toh Koko usse 1 hour me finish karegi”

// 📦 Matlab simple language me

// 👉 Koko har hour max k bananas kha sakti hai

        while(lo<=hi){

            long long mid=hi-(hi-lo)/2;
            long long time=0;

            for(int  i=0;i<piles.size();i++){
                time+=(piles[i]+mid-1)/mid; //isse ceil(pile/mid) Nikalta hai
            }
            if(time<=h){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }

        }
        return lo;

    }
};