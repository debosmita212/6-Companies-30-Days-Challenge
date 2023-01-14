//Leetcode 2212
class Solution {
public:
    int ans=INT_MIN;
    vector<int> tempArr;
    void solve(int i,int numArrows,vector<int> &aliceArrows,int temp,vector<int> &ansArr){
        //base case
        //when index finished and arrays are left or arrays are finished
        if((i<0 && numArrows>=0)|| numArrows==0){
            if(ans< max(ans,temp)){
                //update for 12 places
                for(int j=0;j<12;j++)
                    tempArr[j]=ansArr[j];
                tempArr[0]+=numArrows; //if all arrows arenot used
            }
            ans=max(ans,temp);
            return;
        }
        else if(i<0) return; //when arrows used are more than what is alloted

        //two options
        //take
        if(numArrows>=aliceArrows[i]){
            ansArr[i]=aliceArrows[i]+1;
            solve(i-1,(numArrows-aliceArrows[i]-1),aliceArrows,temp+i,ansArr);
            ansArr[i]=0; //backtrack
        }
        //not take
        solve(i-1,numArrows,aliceArrows,temp,ansArr);
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        tempArr.resize(12,0); //since 0-11
        vector<int> ansArr(12,0);
        //start from last index so started from 11
        solve(11,numArrows,aliceArrows,0,ansArr);
        return tempArr;
    }
};
