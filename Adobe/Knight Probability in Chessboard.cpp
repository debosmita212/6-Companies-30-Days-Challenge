//Leetcode 688
//Memoization solution
class Solution {
public:
    double solve(int n,int k,int row,int col,vector<vector<vector<double>>> & dp){
        //base case
        if(row<0 || col<0 || row>=n || col>=n ) return 0.0;
        if(k==0) return 1.0;
        if(dp[row][col][k]!=-1) return dp[row][col][k];

        double ans=
          //8 directions
        solve(n,k-1,row+2,col+1,dp)+solve(n,k-1,row+1,col+2,dp)+
        solve(n,k-1,row-1,col+2,dp)+solve(n,k-1,row-2,col+1,dp)+
        solve(n,k-1,row-2,col-1,dp)+solve(n,k-1,row-1,col-2,dp)+
        solve(n,k-1,row+1,col-2,dp)+solve(n,k-1,row+2,col-1,dp);

        double res=ans/8.0; //probability so 1/8
        dp[row][col][k]=res;
        return res;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n+1,vector<vector<double>> (n+1,vector<double>(k+1,-1)));
        return solve(n,k,row,column,dp);
    }
};
