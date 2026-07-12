class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        // SIMPLE GREEDY ALGORITHM...

        // Agar previous aur current overlap karte hain...
        // Toh dono me se us interval ko rakhenge
        // Jo sabse jaldi khatam ho (smaller end)
        // Kyuki wo future ke intervals ke liye zyada space chhodta hai.

        sort(intervals.begin(), intervals.end());

        int n = intervals.size();

        int prevEnd = intervals[0][1];

        int count = 0;

        for (int i = 1; i < n; i++) {

            int currStart = intervals[i][0];
            int currEnd   = intervals[i][1];

            // AGAR overlap hai...
            if (currStart < prevEnd) {

                // Ek interval delete karna hi padega
                count++;

                // Agar current jaldi khatam ho raha hai
                // Toh previous ko delete maan lo
                // Aur current ko survivor bana do
                if (currEnd < prevEnd) {
                    prevEnd = currEnd;
                }

                // Warna current delete ho gaya
                // prevEnd same rahega

            }
            else {

                // AGAR overlap hi nahi hai
                // Toh current ab naya previous ban jayega
                prevEnd = currEnd;
            }
        }

        return count;
    }
};