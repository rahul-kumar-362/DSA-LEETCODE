class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //first lets try the Linear Search ALGO

        int m=matrix.size();
        int n=matrix[0].size();

        int lo=0;
        int hi=m*n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int currow=mid/n;
            int currcol=mid%n;
            if(matrix[currow][currcol]==target) return true;
            else if(matrix[currow][currcol]<target)lo=mid+1;
            else hi=mid-1;
        }
        return false;
    }
};