//Leetcode 659
class Solution {
public:
/*
Frequency map
Hypothetical map->checks if a number available to join existing subsequence
*/
    bool isPossible(vector<int>& nums) {
        //frequency map
        unordered_map<int,int> fm;
        for(auto it:nums) fm[it]++;

        //hypothetical map
        unordered_map<int,int> hm;

        for(auto it:nums){
            //if no frequency in frequency map
            if(fm[it]==0) continue;

            //then can be added to existing subsequence
            if(hm[it]>0){
                hm[it]--;
                fm[it]--;
                //as next required element would be it+1
                hm[it+1]++;
            }
            //create new subsequence with this element update in fm
            else if(fm[it]>0 && fm[it+1]>0 && fm[it+2]>0){
                fm[it]--;
                fm[it+1]--;
                fm[it+2]--;
                //also update in hm with next required element
                hm[it+3]++;
            }
            else return false;
        }
        return true;
    }
};
