class Solution {
public:
    int orangesRotting(vector<vector<int>>& arr) {
        int m=arr.size();
        int n=arr[0].size();

    queue<pair<int,int>> q;
    int fresh=0;

    // Initial scan
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==2){
                q.push({i,j});
            }
            else if(arr[i][j]==1){
                fresh++;
            }
        }
    }

    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};

    int minutes = 0;

    while(!q.empty()){
        int sz = q.size();
        bool changed = false; // check if infection spread this round

        while(sz--){
            pair<int,int> UparWala = q.front();
            q.pop();

            int aage = UparWala.first;
            int piche = UparWala.second;

            for(int k=0;k<4;k++){
                int D1 = aage + dir[k][0];
                int D2 = piche + dir[k][1];

                if(D1>=0 && D1<m && D2>=0 && D2<n && arr[D1][D2]==1){
                    arr[D1][D2]=2;
                    q.push({D1,D2});
                    fresh--;
                    changed = true;
                }
            }
        }

        if(changed) minutes++; // only if something rotted
    }

    if(fresh != 0)  return -1;
    return minutes;
    }
};