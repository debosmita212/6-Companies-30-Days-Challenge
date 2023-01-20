//Leetcode 792
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        //map for maintain words frequency
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        int ans=0;
        //iterate through map and check any words are present in s
        for(auto it:mp){
            string str=it.first;
            int i=0; //index for str
            int j=0; //index for s
            while(i<str.size() && j<s.size()){
                //if character matches
                if(str[i]==s[j]) i++;
                j++; //it will move anyway
                //means word is present in s so add the word frequency to ans
                if(i==str.size()) ans+=it.second;
            }
        }
        return ans;
    }
};
