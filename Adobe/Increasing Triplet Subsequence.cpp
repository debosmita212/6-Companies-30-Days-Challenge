//Leetcode 334
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int c1=INT_MAX, c2=INT_MAX;
        for(int x:nums){
            if(x<=c1){
                //c1 is min seen so far(it's a candidate for 1st element)
                c1=x;
            }
            //here when x>c1, i.e x might be either c2 or c3
            else if(x<=c2){
                //x is better than the current c2, store it
                c2=x;
            }
            //here when we have c1<c2 already and x>c2
            else{
                //the increasing subsequence of 3 elements exists
                return true;
            }
        }
        return false;
    }
};
