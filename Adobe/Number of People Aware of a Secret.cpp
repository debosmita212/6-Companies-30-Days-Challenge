//Leetcode 2327
class Solution {
public:
    long dp[1001];
    long mod=1e9+7;
    long solve(int day,int &n,int &delay,int &forget){
        //base case(some people know the secret on this day)
        if(dp[day]!=-1) return dp[day];
        long ans=0;
        ans++; //he is the one who knows the secret already so ans++
        //but at the end of nth day if he forgets the answer don't include ans
        if(day+forget<=n){
            ans--;
        }
        //on what days he can tell the secret
        //from day+delay to min(day+forget,n+1)-1
        for(int start=day+delay;start<min(day+forget,n+1);start++){
            ans+=solve(start,n,delay,forget);
            ans=ans%mod;
        }
        //store in dp array
        dp[day]=ans;
        return ans;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        memset(dp,-1,sizeof(dp));
        return solve(1,n,delay,forget);
    }
};
