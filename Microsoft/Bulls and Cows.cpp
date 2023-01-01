//Leetcode 299
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> mp; //stores character frequency of not bull
        int bull=0;
        int cow=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]) bull++;
            else mp[secret[i]]++;
        }
        for(int i=0;i<secret.size();i++){
            //skipping bull
            if(secret[i]!=guess[i]){
                if(mp[guess[i]]>0){
                    cow++; //characters matched but not position
                    mp[guess[i]]--; //decreasing the frequency
                }
            }
        }
        return to_string(bull)+"A"+to_string(cow)+"B";
    }
};
