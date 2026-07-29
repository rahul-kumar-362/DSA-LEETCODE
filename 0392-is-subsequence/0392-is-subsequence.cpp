class Solution {
public:
    bool isSubsequence(string s, string t) {
        bool flag = false;
        int count = 0;
        int j = 0;
        for(int i=0;i<s.size();i++){
            while(j<t.size() ){
                if(t[j] == s[i]){
                    count++;
                    j++;
                    break;
                }
                j++;
            }
                // if(s[i]==t[j]){
                //     cout<<"s[i] = "<<s[i]<<endl;
                //     cout<<"t[i] = "<<t[j]<<" ";
                //     cout<<endl;
                //     count++;
                //     break;
                // }
            
        }

        if(count == s.size())return true;
        return false;
    }
};