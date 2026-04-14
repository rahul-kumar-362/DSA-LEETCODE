class Solution {
public:

    void solve(vector<char>& s,int i){
        if(i>=s.size()/2)return ;
        swap(s[i],s[s.size()-i-1]);
        solve(s,i+1);
    }
    void reverseString(vector<char>& s) {
        //extra memory nahi chaiye
        solve (s,0);
    }
};