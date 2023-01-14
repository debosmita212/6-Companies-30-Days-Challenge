//Leetcode 502
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>> p;
        for(int i=0;i<n;i++){
            p.push_back({capital[i],profits[i]});
        }
        sort(p.begin(),p.end()); //this will sort them ascending order of their capital
        priority_queue<int> pq; //max-heap
        int i=0;
        while(i<n && k){
            //if capital is less than what's in our hand then push into heap the profit associated with it
            if(w>=p[i].first){
                pq.push(p[i].second);
                i++;
            }
            else{
                //not enough capital to choose from so return current capital
                if(pq.empty()) return w;
                //add it to the current capital since capital will be increased by profit
                w+=pq.top();
                pq.pop();
                k--;
            }
        }
        //still k exists and also capital exist as well 
        while(k && !pq.empty()){
            w+=pq.top();
            pq.pop();
            k--;
        }
        return w;
    }
};
