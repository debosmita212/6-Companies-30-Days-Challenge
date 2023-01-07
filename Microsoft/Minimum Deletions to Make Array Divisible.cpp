//Leetcode 2344
class Solution {
public:
    //divides all elements means divides gcd of all elements
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        //find the gcd of numsDivide
        int g=numsDivide[0];
        for(int i:numsDivide)
            g=gcd(g,i);
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size() && nums[i]<=g; i++){
            if(g%nums[i]==0) return i; //index is the deletion number
        }
        return -1;
    }
};
