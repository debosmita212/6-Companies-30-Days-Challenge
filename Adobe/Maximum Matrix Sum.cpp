//Leetcode 1975
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long neg_count=0;
        int mini=INT_MAX;
        long long sum=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                sum+=abs(matrix[i][j]);
                if(matrix[i][j]<0) neg_count++;
                mini=min(mini,abs(matrix[i][j]));
            }
        }
        //even number of negative signs so just add the absolute value of elements
        if(neg_count%2==0) return sum;
        //odd number of negative signs
        //last negative sign attached with the minimum absolute value 
        //since already once added to sum so minus twice of it
        return sum-2*mini;
    }
};
