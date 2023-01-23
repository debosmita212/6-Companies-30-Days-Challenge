//Leetcode 698
class Solution {
public:
    bool solve(int start,int &target,int currSum,int k,vector<bool> &vis,vector<int> &nums){
        //base case
        if(k==1) return true; //array itself
        //found a subset, search for remaining subsets
        if(target==currSum){
            return solve(0,target,0,k-1,vis,nums);
        }

        for(int i=start;i<nums.size();i++){
            //already visited or target exceeds
            if(vis[i] || currSum+nums[i]>target)continue;

            vis[i]=true;
            if(solve(i+1,target,currSum+nums[i],k,vis,nums))
                return true;
            vis[i]=false; //backtrack
            // since our given array contains duplicate and our function will reach here only if we are not able to find the solution by picking this element, 
      // hence again calling the function by picking same element will not help to get the solution hence we can prune our solution by not considering all these duplicate elements(make sure array must be sorted).
            while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(auto it:nums) sum+=it;
        if(sum%k!=0) return false;
        //since every subset sum will be same
        int target=sum/k;
        vector<bool> vis(nums.size(),false);
        sort(nums.begin(),nums.end());
        return solve(0,target,0,k,vis,nums);
    }
};
