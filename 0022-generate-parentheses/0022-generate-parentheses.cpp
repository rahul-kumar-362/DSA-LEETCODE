class Solution {
public:


    void solve(int open,int close,int n ,vector<string>&ans ,string temp){


        //ohh bc agar open aur close dono n tab return ;

        if(temp.size()==2*n){//jab ssize reach tab pushback
            ans.push_back(temp);
            return;
        }

        if(open<n){
            solve(open+1,close,n,ans,temp+"(");
        }
        if(close<open){ //Matlab: Jitne ( lagaye hain, unse zyada ) kabhi nahi lag sakte.
            solve(open,close+1,n,ans,temp+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        //to generate parentthesis we will use recursion with stack

        string temp="";
        vector<string>ans;
        solve(0,0,n,ans,"");
        return ans;
    }
};