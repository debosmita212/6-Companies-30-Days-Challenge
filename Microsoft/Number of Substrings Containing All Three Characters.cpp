//Leetcode 1358
class Solution {
public:
    int numberOfSubstrings(string s) {
        //maintain a hashmap for characters
        unordered_map<char,int> mp;
        int l=0, r=0, end=s.length()-1;
        int count=0;

        while(r!=s.length()){
            //add the new element into window and add into map
            mp[s[r]]+=1;

            //valid window
            while(mp['a'] && mp['b'] && mp['c']){
                count+=(1+(end-r));
                //shrinking window size by removing the first element
                mp[s[l]]-=1;
                l++;
            }
            r++;
        }
        return count;
    }
};
