class Solution {
public:

    //int dp[1001][1001][1024];
    vector<vector<vector<int>>>dp;

    int solve(int i,int j,vector<vector<int>>& grid,int m,int n,int currXor){
        //right ke liye aur down ke liye

        //💡 Missing concept:
//👉 Har step pe XOR carry karna padega


    

        if(i>=m || j>=n){//bade hue toh break
            
            return INT_MAX;//pata nahi chut  
        }

        currXor^=grid[i][j];//curr Cell include karo


        if(i==m-1 && j==n-1){//pohoch gaye toh kya kare
            return  currXor;
        }

        if(dp[i][j][currXor]!=-1){//2D leta toh chud jaata
        return dp[i][j][currXor];
    }
        int right=solve(i+1,j,grid,m,n,currXor);
        int down=solve(i,j+1,grid,m,n,currXor);
        
        return dp[i][j][currXor] = min(right,down);
        
    }
    int minCost(vector<vector<int>>& grid) {
        //brute force

        //since initial is (0,0);
      //  int pt=grid[0][0];//grid of 0,0

           
            int m=grid.size();
        int n=grid[0].size();

        
        // ✅ proper initialization
        dp = vector<vector<vector<int>>>(m, 
             vector<vector<int>>(n, vector<int>(1024, -1)));


       
        return solve(0,0,grid,m,n,0);
        
    }
};