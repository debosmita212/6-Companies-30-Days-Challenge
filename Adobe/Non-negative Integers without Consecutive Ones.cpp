//Leetcode 600
class Solution {
public:
    int findIntegers(int n) {
        int fib[31]; //10^9
        fib[0]=1;
        fib[1]=2;
        //non consecutive 1s number follows fibonacci series
        for(int i=2;i<30;i++){
            fib[i]=fib[i-1]+fib[i-2];
        }

        int ans=0, count=30, prev_bit_one=0;

        while(count>=0){
            //if bit is 1
            if(n & (1<<count)){
                ans+=fib[count];
                if(prev_bit_one) return ans; //consective 1 is already present so just return ans, don't include the number itself
                prev_bit_one=1;
            }
            else{
                prev_bit_one=0;
            }
            count--;
        }
        return ans+1;//1 for the number itself
    }
};
