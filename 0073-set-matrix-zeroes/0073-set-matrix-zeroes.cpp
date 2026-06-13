class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //row aur column zero karna hai
        int n=matrix.size();
        int m=matrix[0].size();


        //brute force

       vector<bool>makerow(n,false);
       vector<bool>makecolumn(n,false);


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    makerow[i]=true;
                    makecolumn[j]=true;
                }
            }
        }



        //make row 0
        for(int i=0;i<n;i++){
            
            if(makerow[i]){
                for(int j=0;j<m;j++){
                    matrix[i][j]=0;
                }
            }
        }


        //make col 0
        for(int j=0;j<m;j++){
            if(makecolumn[j]){
                for(int i=0;i<n;i++){
                    matrix[i][j]=0;
                }
               
            }
        }

    }
};