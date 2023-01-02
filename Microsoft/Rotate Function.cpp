//Leetcode 396
class Solution {
public:
    //Sliding window approach
    //0 1 2 3 4 5 6 7
    //4 3 2 6 4 3 2 6
    //rotations-> 0-3, 1-4, 2-5, 3-6
    //fn is the first permutation
    //while moving the window we're removing 4*0 and adding 4*4 and also removing sum of the array
    //T.c=O(n) S.C=O(n)
    int maxRotateFunction(vector<int>& nums) {
        long sum=0;
        long fn=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            fn+=(i*nums[i]); //calculating first permutation
        }

        long l=1,r;
        long newfn=fn;
        while(l<nums.size()){
            r=nums.size()+l-1; //l to r ranges changes

            long removed=(l-1)*nums[l-1];
            long added=r*nums[r%nums.size()]; //using mod since we're assuming of rotation

            newfn=newfn-removed+added-sum;
            fn=max(fn,newfn);
            l++;
        }
        return (int)fn;
    }
};
