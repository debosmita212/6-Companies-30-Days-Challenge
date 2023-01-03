//Leetcode 2467
class Solution {
public:
    vector<vector<int>> adj;
    vector<int> par;
    vector<int> dist;
    void dfs(int u,int p=0,int d=0){
        dist[u]=d;
        par[u]=p;
        //check for adjacent nodes
        for(auto it:adj[u]){
            //parent and node are same
            if(it==p) continue;
            dfs(it,u,d+1); //updating node,parent,incrementing distance
        }
    }
    int dfs2(int u,vector<int> &amount,int p=0){
        int ret=amount[u];
        int maxi=-INT_MAX; //leaf node
        //check for adjacent nodes
        for(auto it:adj[u]){
            if(it!=p){
                maxi=max(maxi,dfs2(it,amount,u));
            }
        }
        //if the node is leaf node then return it's amount
        if(maxi==-INT_MAX) return ret;
        else return ret+maxi;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size(); //number of nodes
        //make adjacency list
        adj.resize(n,vector<int>());
        //undirected
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        //Step1 : finding parent and distance array from node 0 using dfs
        par.resize(n);
        dist.resize(n);
        //calling the first dfs
        dfs(0);
        //Step2: update path of Bob from node 0 basically try to make the nodes 0
        // or if they reach together update accordingly
        int curr=bob;
        int bob_dist=0;
        //until 0 node is reached
        while(curr!=0){
            //when bob will reach faster make it 0 as bob consume the node value
            if(dist[curr]>bob_dist){
                amount[curr]=0;
            }
            //when they reach a node together so they consume half
            else if(dist[curr]==bob_dist){
                amount[curr]/=2;
            }

            curr=par[curr]; //as bob goes upwards so parent will be curr now
            bob_dist++; //updating bob distance
        }
        //Step3: dfs to find the total sum to each node
        return dfs2(0,amount);
    }
};
