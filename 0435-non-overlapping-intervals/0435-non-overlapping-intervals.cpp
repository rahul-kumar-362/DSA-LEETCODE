class Solution {
public:

    bool isPrevOverlapped(int &prev1 ,int &prev2,int i,vector<vector<int>>& intervals){
        int curr1 = intervals[i][0];
        int curr2 = intervals[i][1];

        if(prev2>curr1)return true;//since eQual wale ko alag lena padega
        return false;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //SIMPLE GREEDY ALGORITHM ... 
        //AGAR PICHLA WALA OVERLAPPING HAI TOH...


        //check karunga current se,JO bada wo nikal dunga
        //kyuki wo aage jaake aur problems create karega


        int n = intervals.size();

        sort(intervals.begin(),intervals.end());

        int prev1 = intervals[0][0];
        int prev2 = intervals[0][1];


        
        int count=0;

        for(int i=1;i<n;i++){
            if(isPrevOverlapped(prev1,prev2,i,intervals)){//AGAR prev se overlapped hai toh 
                // int currD= intervals[i][1]-intervals[i][0];
                // int prevD = prev2-prev1;

                int curr1 = intervals[i][0];
                int curr2 = intervals[i][1];

                if(curr2>=prev2){//bada ya equal toh lena hi nahi.. //DEKHNA PADEGA
                    count++;//delete kar skte hai
                }
                else{//toh current previous ban jayega
                    count++;
                    prev1 = intervals[i][0];
                    prev2 = intervals[i][1];
                }
            }
            else{
                prev1 = intervals[i][0];
                prev2 = intervals[i][1];
            }
        }
        return count; 
    }
};