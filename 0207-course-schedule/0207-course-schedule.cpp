class Solution {
public:

    bool isCycle(int src,vector<bool>&vis,vector<bool>&rec,vector<vector<int>>&graph){
        vis[src]=true;
        rec[src]=true;

        for(int i=0;i<graph.size();i++){
            int u=graph[i][1];
            int v=graph[i][0];  //since , v<--u

            if(u==src){//jabhi neighbor milega...

                //Tabhi perform DFS wala kaam...

                if(!vis[v]){
                    if(isCycle(v,vis,rec,graph)){
                    return true;
                    }
                }
                else{//if Already visited...
                    if(rec[v]){
                        return true;
                    }
                }
            }
        }
        rec[src]=false;//for backtracking ...
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& graph) {
        int V = numCourses;
        //prerequisites -- Edges INformation 
        //Adjacency List Banata hu ...


        // vector<vector<int>>adjList(V);

        // for( auto & edge : prerequisites){
        //     int u = edge[0];
        //     int v = edge[1]; 

        //     adjList[v].push_back(u);//since opposite dependency condition...
        // }
        //BANGYI ADJ LIST...

        //since we WANT VALID SEQUENCE COURSES DEPENDENCY SATISFY...
        //THAT IS ... TopoLogical Sort...

        //baTana hai HO.. Sakti hai ya nahi...


        //THAT IS BATANA HAI KI ...
        //DAG HAI YA NAHI...



        vector<bool>vis(V,false);
        vector<bool>rec(V,false);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(isCycle(i,vis,rec,graph))return false;
            }
        }
        return true;
    }
};