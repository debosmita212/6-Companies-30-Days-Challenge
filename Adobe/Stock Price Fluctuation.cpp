//Leetcode 2034
class StockPrice {
public:
    unordered_map<int,int> mp;
    multiset<int> ms;
    int latestTime=-1;
    StockPrice() {
        
    }
    //O(logn)
    void update(int timestamp, int price) {
        //if timestamp is already present in map then update it
        if(mp.count(timestamp)){
            // this makes sure that only one of the values equal to `mp[timestamp]` in the multiset is deleted, not all of them

            ms.erase(ms.lower_bound(mp[timestamp]));
        }
        mp[timestamp]=price;
        ms.insert(price);
        latestTime=max(latestTime,timestamp);
    }
    //O(1)
    int current() {
        return mp[latestTime];
    }
    //O(1)
    int maximum() {
        //points to last element
        return *rbegin(ms);
    }
    //O(1)
    int minimum() {
        //points to first element
        return *begin(ms);
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
