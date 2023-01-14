//Leetcode 1169
class Solution {
public:
    vector<string> separate(string &s){
    vector<string> v;
    string t;
    for(auto it : s){
        if(it == ','){
            //all three members will be inserted here
            v.push_back(t);
            t.clear();
        }else{
            t.push_back(it);
        }
    }
    //since last there's no comma so last member will be pushed here
    v.push_back(t);
    return v;
}

vector<string> invalidTransactions(vector<string>& transactions) {
    
    //making a hashmap stores 4 members in a vector
    unordered_map<string , vector<string>> mp;
    for(int i=0;i<transactions.size();i++){
        mp[transactions[i]] = separate(transactions[i]);
    }
    
    vector<string> Invalid;
    for(int i=0;i<transactions.size();i++){
        vector<string> s = mp[transactions[i]];
        //since amount greater than 1000$ will be an invalid case
        if(stoi(s[2]) > 1000){
            Invalid.push_back(transactions[i]);
            continue;
        } 
        for(int j=0;j<transactions.size();j++){
            //making sure to not check the same index
            if(i != j){
                vector<string> t = mp[transactions[j]];
                //it shouldn't start within 60 mins
                if( abs(stoi(t[1]) - stoi(s[1])) <= 60){
                    //name is same but place different so invalid case
                    if(t[0] == s[0] && t[3] != s[3]){
                       Invalid.push_back(transactions[i]);
                        break;
                    } 
                } 
            }
        }
    }
    return Invalid;
}
};
