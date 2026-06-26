class Solution {
public:
    int divide(int dividend, int divisor) {
        long long res=1LL*dividend/divisor;

        if(res>INT_MAX)return INT_MAX;
        else if(res<INT_MIN)return INT_MIN;
        return (int)res;
    }
};