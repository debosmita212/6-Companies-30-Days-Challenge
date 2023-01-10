//Leetcode 172
class Solution {
public:
// How many factors of 5 does this number has
    int trailingZeroes(int n) {
        int count=0;
        while(n){
            n/=5;
            count+=n;
        }
        return count;
    }
};
