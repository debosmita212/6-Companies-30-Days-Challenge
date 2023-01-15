//Leetcode 1814
class Solution {
public:
    /*A[i] + rev(A[j]) == A[j] + rev(A[i])
A[i] - rev(A[i]) == A[j] - rev(A[j])
B[i] = A[i] - rev(A[i])*/
    int rev(int n){
        int temp=0;
        while(n>0){
            temp=temp*10+(n%10);
            n=n/10;
        }
        return temp;
    }
    int countNicePairs(vector<int>& nums) {
        int mod=1e9+7;
        int ans=0;
        unordered_map<int,int> mp;
        for(int &it:nums){
            //checking how many pairs of a[i]-rev(a[i]) exists
            ans=(ans+mp[it-rev(it)]++)%mod;
        }
        return ans;
    }
};
