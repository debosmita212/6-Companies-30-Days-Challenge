//Leetcode 1976
//Dijkstra to find the shortest path
class Solution {
public:
    int mod=1e9+7;
    int dijkstra(vector<pair<int,int>> adj[],int n){
        //min heap for storing the minimum distance
         priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        //distance vector
        vector<long long> dist(n,1e15);
        vector<long long> path(n,0); //stores the number of paths for distances
        pq.push({0,0}); //push the initial distance and node
        //mark the distance and path array
        dist[0]=0;
        path[0]=1;
        while(!pq.empty()){
            //get the minimum distance since it is in the top
            long long distance=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            //check for adjacent nodes
            for(auto it:adj[node]){
                
                int adjNode=it.first;
                long long wt=it.second;

                //if minimum distance exists for a node to reach then update it, path and push into the heap
                if(distance+wt<dist[adjNode]){
                    dist[adjNode]=distance+wt;
                    path[adjNode]=path[node];
                    pq.push({distance+wt,adjNode});
                }
                //same shortest distance then update the path since it'll count the possible choices
                else if(distance+wt==dist[adjNode]){
                    path[adjNode]=(path[node]+path[adjNode])%mod;
                }
            }
        }
        //since it'll contain how many number of ways one reach the last node
        return path[n-1];
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        //make adjacency list
        vector<pair<int,int>> adj[n];
        //since bidirectional
        for(auto &it:roads){
            adj[it[0]].push_back({it[1],it[2]}); 
            adj[it[1]].push_back({it[0],it[2]});
        }

        return dijkstra(adj,n);
    }
};
