//Leetcode 174
class Solution {
public:
//Memoization
    int solve(int i,int j,vector<vector<int>>& dungeon,int n,int m,vector<vector<int>> &dp){
        //base case
        //out of boundary
        if(i==n || j==m) return 1e9; 
        //reached
        if(i==n-1 && j==m-1){
            if(dungeon[i][j]<=0){ //negative cell so add 1 to get the positive res
                return -dungeon[i][j]+1;
            }
            else return 1;
        }
        if(dp[i][j]!=1e9) return dp[i][j];
        //going to all possible paths
        int right=solve(i,j+1,dungeon,n,m,dp);
        int down=solve(i+1,j,dungeon,n,m,dp);

        int minHealthRequired=min(right,down)-dungeon[i][j];
        if(minHealthRequired<=0){
            dp[i][j]=1;
        }
        else{
            dp[i][j]=minHealthRequired;
        }
        return dp[i][j];
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        vector<vector<int>> dp(n,vector<int>(m,1e9));
        return solve(0,0,dungeon,n,m,dp);
    }
};
