class Solution {
public:

  //EXtreme BRUTE FORCE... looping all
    void solve(int i,string digits,string temp,vector<string>&ans,string two,string three,string four,string five,string six,string seven,string eight,string nine){
        int n=digits.size();//itni jagah par daalna hai combinations

        // string two="abc";
        // string three = "def";
        // string four = "ghi";
        // string five = "jkl";
        // string six = "mno";
        // string seven = "pqrs";
        // string eight = "tuv";
        // string nine = "wxyz";

        if(temp.size()==n){
            ans.push_back(temp);
            return ;
        }
        if(i==n){
            return;
        }

        if(digits[i]=='2'){
            for(int j=0;j<two.size();j++){
                char c = two[j];

                temp+=c;
                solve(i+1,digits,temp,ans,two,three,four,five,six,seven,eight,nine);
                temp=temp.substr(0,temp.size()-1);//remove last
            }
        }
        else if(digits[i]=='3'){
             for(int j=0;j<three.size();j++){
                char c = three[j];

                temp+=c;
                solve(i+1,digits,temp,ans,two,three,four,five,six,seven,eight,nine);
                temp=temp.substr(0,temp.size()-1);//remove last
            }
        }
        else if(digits[i]=='4'){
             for(int j=0;j<four.size();j++){
                char c = four[j];

                temp+=c;
                solve(i+1,digits,temp,ans,two,three,four,five,six,seven,eight,nine);
                temp=temp.substr(0,temp.size()-1);//remove last
            }
        }
        else if(digits[i]=='5'){
             for(int j=0;j<five.size();j++){
                char c = five[j];

                temp+=c;
                solve(i+1,digits,temp,ans,two,three,four,five,six,seven,eight,nine);
                temp=temp.substr(0,temp.size()-1);//remove last
            }
        }
        else if(digits[i]=='6'){
            for(int j=0;j<six.size();j++){
                char c = six[j];

                temp+=c;
                solve(i+1,digits,temp,ans,two,three,four,five,six,seven,eight,nine);
                temp=temp.substr(0,temp.size()-1);//remove last
            } 
        }
        else if(digits[i]=='7'){
             for(int j=0;j<seven.size();j++){
                char c = seven[j];

                temp+=c;
                solve(i+1,digits,temp,ans,two,three,four,five,six,seven,eight,nine);
                temp=temp.substr(0,temp.size()-1);//remove last
            }
        }
        else if(digits[i]=='8'){
             for(int j=0;j<eight.size();j++){
                char c = eight[j];

                temp+=c;
                solve(i+1,digits,temp,ans,two,three,four,five,six,seven,eight,nine);
                temp=temp.substr(0,temp.size()-1);//remove last
            }
        }
        else if(digits[i]=='9'){
             for(int j=0;j<nine.size();j++){
                char c = nine[j];

                temp+=c;
                solve(i+1,digits,temp,ans,two,three,four,five,six,seven,eight,nine);
                temp=temp.substr(0,temp.size()-1);//remove last
            }
        }
        // for(int i=0;i<n;i++){
        //     choose(digits[i]);
        // }
    }
    vector<string> letterCombinations(string digits) {
        string two="abc";
        string three = "def";
        string four = "ghi";
        string five = "jkl";
        string six= "mno";
        string seven = "pqrs";
        string eight = "tuv";
        string nine = "wxyz";
        int n=digits.size();

        //since jitne no. utne loops...
        vector<string>ans;
        //string temp=""
        solve(0,digits,"",ans,two,three,four,five,six,seven,eight,nine);
        return ans;
    }
};