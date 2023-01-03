//Leetcode 207
//BFS Solution
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //adjacency list
        vector<int> adj[numCourses];
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        //indegree initialized with 0
        vector<int> indegree(numCourses,0);
        //calculate all indegrees
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i])
                indegree[it]++;
        }
        queue<int> q;
        //pushing nodes with indegree 0
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            //check for adjacent and reduce indegree by 1
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        if(count==numCourses) return true; //no cycle as topological sort exists
        return false;
    }
};
