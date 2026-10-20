class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //O(log(m*n))

        int m=matrix.size();
        int n=matrix[0].size();

        int st = 0;
        int end = m*n-1;
        while(st <= end){
            int mid = st + (end - st)/2;
            int currow = mid/n;
            int currcol = mid%n;
            if( matrix[currow][currcol] ==target )return true;
            else if( matrix[currow][currcol]<target )st=mid+1;
            else end=mid-1;
        }
        return false;
    }
};