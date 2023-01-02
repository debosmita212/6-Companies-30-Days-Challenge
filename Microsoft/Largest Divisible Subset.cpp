//Leetcode 368
class Solution {
public:
    //Memoization
    void lds(vector<int> &nums,int i,int prev,vector<int> &temp,vector<int> &ans,vector<int> &dp){
        //base case
        if(i>=nums.size()){
            //stores maximum size subset
            if(temp.size()>ans.size()) ans=temp;
            return;
        }

        if((int)temp.size()>dp[i] && (nums[i]%prev==0)){
            dp[i]=temp.size(); //update dp array
            temp.push_back(nums[i]);
            lds(nums,i+1,nums[i],temp,ans,dp); //change the prev and increment index
            temp.pop_back(); //backtrack
        }
        //doesn't match the condition so prev remains same
        lds(nums,i+1,prev,temp,ans,dp);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //sort the array
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size(),-1);
        vector<int> temp;
        vector<int> ans;
        lds(nums,0,1,temp,ans,dp);
        return ans;
    }
};
