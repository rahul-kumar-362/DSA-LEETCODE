class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //Brute Approach 
        int n=fruits.size();

        //since its similar to 2 sum 

        //we have to choose max along hence,sliding window



        if(n==1)return 1;

        unordered_map<int,int>distinctCount;
        int maxi=0;

        int L=0;

        
        for(int r=0;r<n;r++){
            // int j=i+1;
            // while(j<n){
                distinctCount[fruits[r]]++;
                int distANS=0;


                //if(distinctCount.size())
                if(distinctCount.size()<=2){  //since question asked for ATMOST 2 distinct 

                
                    //toh store
                    distANS = r-L+1;
                    //maxi=max(maxi,distAns);
                }

                
                else if(distinctCount.size()>2){


                    while( distinctCount.size()>2){
                        distinctCount[fruits[L]]--;
                        if(distinctCount[fruits[L]]==0)distinctCount.erase(fruits[L]);

                        L++;
                    }
                }

                maxi=max(maxi,distANS);
            // }
        }
        return maxi;
    }
};