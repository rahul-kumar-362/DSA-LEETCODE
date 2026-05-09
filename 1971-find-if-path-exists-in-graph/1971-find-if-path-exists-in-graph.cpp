class Solution {
public:

    bool hasPath(int source,int destination,vector<bool>&visited, vector<vector<int>>& adj){

        //adj is adjacency list here pehLe WO banani pdti hai
        if(source==destination)return true;

        visited[source]=true;
        for(auto &v : adj[source] ){
            if(!visited[v]){
                if(hasPath(v,destination,visited,adj))return true;
            } 
        }
            return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool>visited(n,false);
        //ADJACENCY LIST BANAO

        vector<vector<int>>adj(n);

        for(auto &e : edges){

            int u=e[0];
            int v=e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return hasPath(source,destination, visited  , adj);
    }
};