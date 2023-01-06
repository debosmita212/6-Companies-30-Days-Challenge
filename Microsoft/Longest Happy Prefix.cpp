//Leetcode 1392
//KMP algorithm
class Solution {
public:
    string longestPrefix(string s) {
        string ans="";
        vector<int> lps(s.length(),0);
        int i=0, j=1;
        while(j<s.length()){
            if(s[i]==s[j]){
                lps[j]=i+1;
                i++;
                j++;
            }
            else if(i!=0){
                i=lps[i-1];
            }
            else{
                j++;
            }
        }
        ans=s.substr(0,i);
        return ans;
    }
};
