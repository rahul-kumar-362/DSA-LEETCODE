class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {//BRUTE FORCE...O(n*m)
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                int left = (j-1>=0)?mat[i][j-1]:INT_MIN;
                int right = (j+1<m)?mat[i][j+1]:INT_MIN;
                int top = (i-1>=0)?mat[i-1][j]:INT_MIN;
                int bottom = (i+1<n)?mat[i+1][j]:INT_MIN;

                if((mat[i][j]>left && mat[i][j]>right) 
                && (mat[i][j]>top && mat[i][j]>bottom))return {i,j};
            }
        }  
        return {-1,-1};  
    }
};