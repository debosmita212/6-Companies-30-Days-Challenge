//Leetcode 447
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res=0;

        for(int i=0;i<points.size();i++){
            //distance d, count of all points at distance d from i
            unordered_map<long,int> mp(points.size());
            for(int j=0;j<points.size();j++){
                if(j==i) continue; //same point
                int dy=points[i][1]-points[j][1];
                int dx=points[i][0]-points[j][0];
                //distance
                int key=dy*dy+dx*dx;
                mp[key]++; //increase count of same distance
            }
            for(auto it:mp){
                if(it.second>1){
                    /*
                    number of ways to selecting 2 from n is nP2=n*(n-1)
                    */
                    res+=(it.second*(it.second-1));
                }
            }
        }
        return res;
    }
};
