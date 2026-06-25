class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int L=0;
        int r=0;
        int hash[26]={0};
        int maxf=0;
        int maxlen=0;
        while(r<n){
            hash[s[r]-'A']++;//increase 
            maxf=max(maxf,hash[s[r]-'A']);

            if(((r-L+1)-maxf) > k){//not valid
                hash[s[L]-'A']--;//reduce IT
            //    maxf=0;//redefine
                // for(int i=0;i<26;i++){
                //     maxf=max(maxf,hash[i]);
                // }
                L++;
            }


            //if VALID SEGMENT
            if((r-L+1)-maxf<=k){
                maxlen=max(maxlen,r-L+1);
            }

            r++;
        }
        return maxlen;
    }
};