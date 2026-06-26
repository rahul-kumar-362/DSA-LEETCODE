class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor)return 1;

        bool sign = true;//choose +ve initially

        if(dividend>=0 && divisor<0)sign=false;//case 1: for -ve
        else if(dividend<0 && divisor>=0)sign=false;

        long n= abs((long)dividend);
        long d = abs((long)divisor);

        long quotient = 0;


        while(n>=d){//jabtak numerator denominator ke eQual ya Bada ho ...logn time
            int count=0;
            while(n>=(d<<count+1)){//jabtak n bada ho d*2^count+1 se tabtak
                count++;
            }
            quotient += 1<<count;
            n -= d<<count; 
        }

        if(quotient == 1<<31 && sign){
            return  INT_MAX;
        }

        
        if(quotient == 1<<31 && !sign){
            return  INT_MIN;
        }


        return sign ? quotient : -quotient;//+ve toh + warna -


    }
};