class Solution {
public:
    int mySqrt(int x) {
        //HENCE TO find Out the square value<=X we'll use binary Search algo...

        int st = 1;
        int end = x;
        while(st<=end){
            int mid = st+(end-st)/2;
            if(1LL*mid*mid>x){//valid nahi toh ...
                end = mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return end;
    }
};