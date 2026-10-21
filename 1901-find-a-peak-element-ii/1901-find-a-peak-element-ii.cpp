class Solution {
public:

    int maxIdx(vector<vector<int>>&mat,int mid){//T.C.----O(NlogM)
        int n = mat.size();
        int maxi = -1;
        int maxiD = 0;
        for(int i=0;i<n;i++){
            if(mat[i][mid]>maxi){
                maxi = mat[i][mid];
                maxiD = i;
            }
        }
        return maxiD;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {//BRUTE FORCE...O(n*m)
        int n = mat.size();
        int m = mat[0].size();

        int st = 0;
        int end = m-1;

        while(st<=end){

            int mid = st + (end - st)/2;//BICHWALA COLUMN PAKDO
            int maxMid = maxIdx(mat,mid);

            int left = (mid-1>=0)?mat[maxMid][mid-1]:-1;
            int right = (mid+1<m)?mat[maxMid][mid+1]:-1;
                // int top = (i-1>=0)?mat[i-1][j]:INT_MIN;
                // int bottom = (i+1<n)?mat[i+1][j]:INT_MIN;

               if(mat[maxMid][mid] > left && mat[maxMid][mid] > right){//TOP - BOTTOM SE TOH BADA HI HAI...
                    return {maxMid,mid};
               }
               else if(left>mat[maxMid][mid]){//MATLAB PURE COLUMN SE BHI BADA HAI TOH PEAK LEFT MAI
                    end = mid - 1;
               }
               else{//right>maxMid --- MATLAB RIGHT MAI PEAK
                    st = mid + 1;
               }
        }
        return {-1,-1};  
    }
};