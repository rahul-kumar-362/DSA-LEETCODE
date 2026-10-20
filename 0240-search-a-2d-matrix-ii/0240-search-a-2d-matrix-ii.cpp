class Solution {
public:
    bool bS(vector<int>&a,int target){//O(n*logm)---T.C.
        int st = 0;
        int end = a.size()-1;
        while(st<=end){
            int mid = st + (end - st)/2;
            if(a[mid]==target){
                return true;
            }
            else if(a[mid]<target){
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //BETTER O(N + logM)
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            if(matrix[i][0]<=target  && matrix[i][m-1]>=target){
                if(bS(matrix[i],target))return true;//AGAR TRUE TOH RETURN
            }
        }
        return false;
    }
};