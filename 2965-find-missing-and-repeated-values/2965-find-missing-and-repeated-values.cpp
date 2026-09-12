class Solution {
public:
    //General solution 

    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {


        int repeating = -1;
        int missing = -1;
        unordered_map<int,int>mpp;
        int n = grid[0].size();
        int m = grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mpp[grid[i][j]]++;
            }
        }


        for(auto i : mpp){
            if(i.second == 2) repeating = i.first; 
        }

        for(int i=1;i<=m*n;i++){
            if(!mpp.count(i)){
                missing = i;
                break;
            }
        }

        return {repeating,missing};
    }
};