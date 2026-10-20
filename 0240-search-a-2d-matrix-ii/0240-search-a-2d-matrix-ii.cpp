class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {//O(log(M+N))
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0;
        int col = m-1;  
        while(row<n && col>=0){//jabtak row aur column valid  -->right kone se left
            if(matrix[row][col]==target)return true;
            else if(matrix[row][col]>target)col--;
            else row++;
        }
        return false;
    }
};