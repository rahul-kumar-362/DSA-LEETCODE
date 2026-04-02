class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//        ⏱️ Complexity : 
//           Time: O(m + n) 🔥
//           Space: O(1)

        int m=matrix.size();
        int n=matrix[0].size();

        int row=0;
        int col=n-1;//SINCE starting from TOP-right Corner


        while(row<m && col>=0){//jabtak valid row aur col
            if(matrix[row][col]==target)return true;
            else if(matrix[row][col]>target){//LEFT jao
                col--;
            }
            else{
                row++;//go down
            }
        }



        return false;
    }
};