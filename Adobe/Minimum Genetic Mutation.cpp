//Leetcode 433
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        //set contains all valid mutation
        unordered_set<string> st(bank.begin(),bank.end());
        if(!st.count(endGene)) return -1; //not valid 
        //BFS
        queue<string> q;
        q.push(startGene);
        int steps=0,s;
        string curr;
        vector<char> available={'A','C','G','T'};
        //visited set
        unordered_set<string> vis;
        vis.insert(startGene);
        while(!q.empty()){
            s=q.size();
            while(s--){
                curr=q.front();
                q.pop();
                //reached the end mutation
                if(curr==endGene) return steps;
                //check for 4 options for 8 times as length should be 8
                //at each index we check the possibility of mutation by replacing it with A,C,G,T
                for(int i=0;i<8;i++){
                    char temp=curr[i];
                    //replacing characters
                    for(int j=0;j<4;j++){
                        curr[i]=available[j];
                        //if present in st but not visited
                        if(st.find(curr)!=st.end()){
                            //push into queue and mark visited
                            if(vis.find(curr)==vis.end()){
                                q.push(curr);
                                vis.insert(curr);
                            }
                        }
                    }
                    //replacing with original one
                    curr[i]=temp;
                }
            }
            steps++;
        }
        return -1;
    }
};
