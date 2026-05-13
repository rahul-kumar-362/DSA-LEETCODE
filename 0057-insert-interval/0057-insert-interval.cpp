class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        int n = intervals.size();

        vector<vector<int>> result;

        int st = newInterval[0];
        int end = newInterval[1];

        int i = 0;

        // pehle saare left non-overlapping intervals daalo
        while (i < n && intervals[i][1] < st) {
            result.push_back(intervals[i]);
            i++;
        }

        // overlapping intervals merge karo
        while (i < n && intervals[i][0] <= end) {

            st = min(st, intervals[i][0]);

            end = max(end, intervals[i][1]);

            i++;
        }

        // merged interval push karo
        result.push_back({st, end});

        // remaining intervals
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};