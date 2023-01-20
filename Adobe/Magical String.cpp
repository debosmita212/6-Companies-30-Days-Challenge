//Leetcode 481
class Solution {

/*
initial string is 122 and then keep on adding 1 or 2 x number of times; this x is determined by the s[ind] where ind starts from 2,s[2]=2 then add two 1s to string and then flip the character to 2, s[3]=1 so add one 2 to s and goes on like this
*/

public:
    char flip(char c){
        if(c=='1') return '2';
        else return '1';
    }

    int magicalString(int n) {
        //initial string
        string s="122";
        char next='1';
        int ind=2;
        int ans=1; //already one 1 is present
        while(s.size()<n){
            int temp=s[ind]-'0'; 
            while(temp--){
                s.push_back(next);
                if(s.size()<=n && next=='1')
                    ans+=1; //only count for 1s
                else ans+=0;
            }
            ind++;
            next=flip(next);
        }
        return ans;
    }
};
