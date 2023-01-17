//Leetcode 166
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(!numerator) return "0"; //since numerator is 0
        string ans="";
        //handle the negative case
        if(numerator>0 ^ denominator>0) ans+='-';
        //first case where exact mutilple
        long num=labs(numerator);
        long den=labs(denominator);
        long q=num/den;
        long r=num%den;
        ans+=to_string(q);
        if(r==0) return ans;

        //Second and third case
        ans+='.';
        unordered_map<long,int> mp;//stores position where repeating of number starts in front of remainder
        while(r!=0){
            //repeating case
            if(mp.find(r)!=mp.end()){
                /*
                If the remainder is already in the map then we insert the “(” opening bracket at the position of that rem and lastly append a “)” closing bracket and break out of the loop and return the ans.
                */
                int pos=mp[r];
                ans.insert(pos,"(");
                ans+=")";
                break;
            }
            else{
                //not repeating but decimal one
                /*
                if remainder is not zero and then make the remainder 10 times everytime and append the quotient to the ans string.
                */
                mp[r]=ans.length();
                r*=10;
                q=r/den;
                r=r%den;
                ans+=to_string(q);
            }
        }
        return ans;

    }
};
