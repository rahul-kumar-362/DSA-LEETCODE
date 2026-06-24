class Solution {
public:

//     Complexity
// Time: O(n)
// Space: O(n)
    string convert(string s, int numRows) {
        //brute force....
        vector<string>ans(numRows,"");//initially

        int n=s.size();
        if(numRows==1)return s; // ye hai jab no zigzag

        int r=0;
        int tot=0;
        while(tot<n){
            // int idx=i%(numRows);
            // ans[idx]+=s[r];
            while(tot<n && r<numRows){
                ans[r]+=s[tot];
                r++;
                tot++;
            }
            r-=2;//kyuki loop khatam hone par 2 plus
            while(tot<n && r!=0){
                ans[r]+=s[tot];
                r--;
                tot++;
            }
        }
        string result="";
        for(int i=0;i<ans.size();i++){
            result+=ans[i];
        }
        return result;
    }
};