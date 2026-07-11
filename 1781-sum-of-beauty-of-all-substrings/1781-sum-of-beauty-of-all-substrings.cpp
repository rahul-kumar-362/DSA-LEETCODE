class Solution {
public:
    int beautySum(string s) {//saare substrings ke liye
        //BRUTE FORCE APPROACH
        int n=s.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                vector<int>hashmapp(26,0);
                for(int k=i;k<=j;k++){
                    hashmapp[s[k]-'a']++;
                }
                int maxi=0;
                int mini=500;
                for(int l=0;l<26;l++){
                    maxi=max(maxi,hashmapp[l]);
                    if(hashmapp[l]>0){
                        mini=min(mini,hashmapp[l]);//0 ka dekh lenge
                    }
                }

             count+=abs(maxi-mini);  
            }
        }
            return count;
        }
};