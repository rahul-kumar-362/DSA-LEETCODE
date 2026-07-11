class Solution {
public:

    bool isPalindrome(string &s, int left, int right){

        while(left < right){

            if(s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    string longestPalindrome(string s) {

        int n = s.length();

        string result = s.substr(0,1);
        int size = 1;

        for(int i = 0; i < n; i++){

            for(int len = 1; len <= n-i; len++){

                int j = i + len - 1;

                if(isPalindrome(s,i,j)){

                    if(len > size){
                        size = len;
                        result = s.substr(i,len);
                    }
                }
            }
        }

        return result;
    }
};