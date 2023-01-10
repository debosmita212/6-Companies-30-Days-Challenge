//Leetcode 593
class Solution {
public:
//(x2-x1)^2+(y2-y1)^2
    double distance(vector<int> p1,vector<int> p2){
        return ((p2[0]-p1[0])*(p2[0]-p1[0]))+((p2[1]-p1[1])*(p2[1]-p1[1]));
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points={p1,p2,p3,p4};
        set<double> st;
        //check all pairs distance
        for(int i=0;i<4;i++){
            for(int j=i+1;j<4;j++){
                double temp=distance(points[i],points[j]);
                if(temp!=0) st.insert(temp);
                //temp 0 means same point 2 times
                else return false;
            }
        }
        //there should be 2 distances side distances or diagonal distances
        return st.size()==2;
    }
};
