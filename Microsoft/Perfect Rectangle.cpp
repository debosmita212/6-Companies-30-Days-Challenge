//Leetcode 391
class Solution {
public:
//all the points except the corner ones should appear for even times and four corner points should appear once
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int> mp;
        for(vector<int> &rect:rectangles){
            mp[{rect[0],rect[1]}]++; //xi,yi
            mp[{rect[0],rect[3]}]--; //xi,bi
            mp[{rect[2],rect[1]}]--; //ai,yi
            mp[{rect[2],rect[3]}]++; //ai,bi
        }
        int corners=0;
        for(auto &cnt:mp){
            corners+=abs(cnt.second);
        }
        return corners==4;
    }
};
