//Leetcode 581
class Solution {
public:
    /*
    APPROACH: We need to find the breaking points from both the sides
    then the length between those points will be the answer
    T.C=O(NlogN) S.C=O(N)
    */
    int findUnsortedSubarray(vector<int>& nums) {
        //take another array and sort the elements there
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());

        //compare both the arrays and find the breaking points
        int s=0, e=nums.size()-1;
        while(s<e && nums[s]==temp[s]) s++;
        while(e>=0 && nums[e]==temp[e]) e--;
        
        if(e<0 || s>=e) return 0; //all elements are already sorted
        return e-s+1; //length between breaking points
    }
};
