//Leetcode 440
class Solution {
public:
    int64_t count(int64_t prefix,int64_t n){
        if(prefix>n) return 0;
        else if(prefix==n) return 1; //only one number

        int64_t minPrefix=prefix, maxPrefix=prefix;
        int64_t cnt=1;
        //numbers can only be in range of minPrefix and maxPrefix
        //1-9,10-19,100-199
        while(1){
            minPrefix=10*minPrefix;
            maxPrefix=10*maxPrefix+9;
            if(n<minPrefix) break;
            if(minPrefix<=n && n<=maxPrefix){
                cnt+=(n-minPrefix+1);
                break;
            }
            else{
                cnt+=(maxPrefix-minPrefix+1);
            }
        }
        return cnt;
    }
    int64_t findKthNumber(int64_t n, int64_t k,int64_t prefix=0) {
        //if prefix 0 then count from 1-9
        //otherwise assign 0
        for(int64_t i=(prefix==0?1:0);i<=9;i++){
            if(k==0) return prefix; 
            int64_t numbers_prefix_i_less_n=count(prefix*10+i,n);
            if(numbers_prefix_i_less_n>=k){
                //k is within this prefix range
                return findKthNumber(n,k-1,prefix*10+i);
            }
            else{
                k-=numbers_prefix_i_less_n; //go for another prefix for which we gonna calculate the numbers
            }
        }
        return prefix;
    }
};
