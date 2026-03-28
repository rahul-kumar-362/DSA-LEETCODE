class Solution {
public:

    
   vector<vector<int>>dp;
  int gridWays(int r,int c,int m,int n)
  {

    if(dp[r][c]!=-1){
        return dp[r][c];
    }
    if(r==m-1 || c==n-1)//Base Case
    {
      return 1;
    }
    if(r>=m || c>=n)//Agar side wale cells mai pohcha toh
    {
      return 0;
    }

    int val1=gridWays(r,c+1,m,n);//Right call
    int  val2=gridWays(r+1,c,m,n);//Down call
    return dp[r][c] = val1+val2;
      }


    int uniquePaths(int m, int n) {
        dp.resize(m, vector<int>(n, -1)); // initialize
        return gridWays(0,0,m,n);
    }
};