//Leetcode 216
class Solution {
public:
    int sum(vector<int> &res){
        int s=0;
        for(int i=0;i<res.size();i++)
            s+=res[i];
        return s;
    }
    //Backtracking problem
    void solve(int k,int n,vector<int> &res,vector<vector<int>> &ans,int num){
        //base case
        if(k==0){
            //check if sum==n
            if(sum(res)==n) ans.push_back(res);
            return;
        }
        if(num>9) return; //out of bound
        //Two options either take the number and decrease k by 1
        //or not taking the number k stays same

        res.push_back(num); //take the number
        solve(k-1,n,res,ans,num+1); //decreasing k
        res.pop_back(); //backtrack not taking the number
        solve(k,n,res,ans,num+1);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> res;
        solve(k,n,res,ans,1); //since numbers start from 1 and goes upto 9
        return ans;
    }
};
