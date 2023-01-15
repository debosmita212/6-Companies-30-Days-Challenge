//Leetcode 2151
class Solution {
public:
    int n=0;
    int ans=0;
    bool isValid(vector<vector<int>> &statements,string &curr){
        for(int i=0;i<n;i++){
            if(curr[i]=='1'){
                for(int j=0;j<n;j++){
                    if(statements[i][j]!=2 && statements[i][j]!=curr[j]-'0')
                        return false;
                }
            }
        }
        return true;
    }
    void dfs(vector<vector<int>> &statements,string &curr,int i,int count){
        //base case
        if(i==n){
            //if valid, update the ans by maximum good person found till now
            if(isValid(statements,curr))
                ans=max(ans,count);
            return;
        }
        curr.append(1,'0');
        dfs(statements,curr,i+1,count); //assuming ith person is bad
        curr.back()='1';
        dfs(statements,curr,i+1,count+1); //assuming ith person is good
        curr.pop_back();
    }
    int maximumGood(vector<vector<int>>& statements) {
        n=statements.size();
        string curr="";
        curr.reserve(n);
        dfs(statements,curr,0,0);
        return ans;
    }
};
