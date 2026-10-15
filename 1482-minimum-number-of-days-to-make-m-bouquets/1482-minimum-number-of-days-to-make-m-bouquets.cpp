class Solution {
public: 

//alag bouquet bhi banana hai aur upar se nahi toh -1

// i = 1 rakh skta hu jo har baar badhe fir count kar skte kitno se bada ya equal





    int minDays(vector<int>& bloomDay, int m, int k) {

        if (1LL * m * k > bloomDay.size())return -1;
        int n = bloomDay.size();
        //SINCE WE KNOW DAYS WILL BE in SORTED ORDER ,LETS make a shot

        //invalid invalid valid valid valid,--->similar to smallest divisor


        int st = *min_element(bloomDay.begin(),bloomDay.end());
        int end = *max_element(bloomDay.begin(),bloomDay.end());
        while(st<=end){

            int mid = st + (end - st)/2;//will act as DAY

            int i = 0;  // Har naye din se dobara shuru
            int Block = 0;
            int count = 0;
            while(i<n){
                if(bloomDay[i]<=mid){
                    count++;
                    if(count==k){
                        count = 0;
                        Block++;
                        // if(Block>=m){
                        //     return mid;
                        // }
                    }
                }
                else{
                    count = 0;
                }
                i++;
            }
            if(Block>=m){
                end = mid - 1;//days milgye lekin smallest dhundhna hai
            }
            else{
                st = mid + 1;
            }
        }
        return st;
    }
};