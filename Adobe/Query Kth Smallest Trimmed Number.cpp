//Leetcode 2343
class Solution {
public:
    //find substring and sort
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto q:queries){
            int k=q[0], trim=q[1];
            vector<pair<string,int>> temp; //string, index
            for(int j=0;j<nums.size();j++){
                int n=nums[j].size(); //string size
                string str=nums[j].substr(n-trim);
                if(str.size()) temp.push_back({str,j});
            }
            sort(temp.begin(),temp.end());
            ans.push_back(temp[k-1].second); //kth smallest index
        }
        return ans;
    }
};
