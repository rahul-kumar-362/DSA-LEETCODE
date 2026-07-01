class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        // 4 directions
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        // Step 1: Put all rotten oranges into queue
        //         Count fresh oranges
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]==2){
                    q.push({i,j});
                }

                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        // No fresh oranges
        if(fresh==0) return 0;

        int minutes = 0;

        // Step 2: BFS
        while(!q.empty()){

            int sz = q.size();

            // Process one level
            while(sz--){

                auto front = q.front();
                q.pop();

                int row = front.first;
                int col = front.second;

                for(int k=0;k<4;k++){

                    int nr = row + dx[k];
                    int nc = col + dy[k];

                    if(nr>=0 && nr<n &&
                       nc>=0 && nc<m &&
                       grid[nr][nc]==1){

                        grid[nr][nc]=2;
                        fresh--;

                        q.push({nr,nc});
                    }
                }
            }

            // Increase time only if new oranges were added
            if(!q.empty())
                minutes++;
        }

        if(fresh>0) return -1;

        return minutes;
    }
};