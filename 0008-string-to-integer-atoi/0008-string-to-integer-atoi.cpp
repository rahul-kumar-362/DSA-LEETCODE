class Solution {
public:
    int myAtoi(string s) {

        bool isneg = false;
        int i = 0;

        // skip leading spaces
        while(i < s.size() && s[i] == ' ')
            i++;

        // sign check
        if(i < s.size() && (s[i] == '-' || s[i] == '+')) {
            if(s[i] == '-')
                isneg = true;
            i++;
        }

        string wait = "";

        for(; i < s.size(); i++) {

            // skip leading zeros only if no digit is stored yet
            if(wait.empty() && s[i] == '0') {
                while(i < s.size() && s[i] == '0')
                    i++;

                if(i == s.size())
                    return 0;
            }

            // collect digits
            if(i < s.size() && isdigit(s[i])) {
                wait += s[i];
            }
            else {
                break;
            }
        }

        if(wait.empty())
            return 0;

        long long num = 0;

        for(char ch : wait) {
            num = num * 10 + (ch - '0');

            if(!isneg && num > INT_MAX)
                return INT_MAX;

            if(isneg && -num < INT_MIN)
                return INT_MIN;
        }

        return isneg ? -num : num;
    }
};