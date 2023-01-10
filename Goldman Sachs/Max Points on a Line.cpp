//Leetcode 149
/*
Approach: points which are on the same slope means they are in a straight line,
counting them and take max of different slope counts. Return the max count
*/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n<=2) return n;
        int ans=0;

        for(auto it1:points){
            unordered_map<double,int> mp; //slope,count of points
            double x1=it1[0], y1=it1[1];
            for(auto it2:points){
                if(it2==it1) continue;
                double x2=it2[0], y2=it2[1];
                double slope;
                if(x2-x1==0){
                    //slope is infinity for vertical line
                    slope=INT_MAX;
                }
                else{
                    slope=(y2-y1)/(x2-x1);
                }
                mp[slope]++;
                ans=max(ans,mp[slope]);
            }
        }

        return ans+1; //including point i
    }
};
