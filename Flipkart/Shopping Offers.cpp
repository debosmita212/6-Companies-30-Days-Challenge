//Leetcode 638
class Solution {
public:
//to store the needs remaining state so that we can prune our backtrack tree as needs remaining can be reached by different order of the offers taken. 
    map<vector<int>,int> state;
    int noOffers(vector<int> &price,vector<int> &needs){
        int totalPrice=0;
        for(int i=0;i<price.size();i++)
            totalPrice+=price[i]*needs[i];
        return totalPrice;
    }
    void subtractOffer(vector<int> &offer,vector<int> &needs){
        for(int i=0;i<needs.size();i++)
            needs[i]-=offer[i];
    }
    //in this question, there can't be any negative needs that means consumer cannot take more than what is needed
    bool noNegativeNeed(vector<int> &needs){
        for(auto need:needs){
            if(need<0)
                return false;
        }
        return true;
    }
    void addOffer(vector<int> &offer,vector<int> &needs){
        for(int i=0;i<needs.size();i++)
            needs[i]+=offer[i];
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if(state[needs]) return state[needs];
        //calculate totalPrice without any special offers
        int bestPrice=noOffers(price,needs);

        for(auto offer:special){
            //subtract elements by giving special offers
            //Apply it to the current needs
            subtractOffer(offer,needs);
            //Check if needs doesn't have any negative values, i.e. that we are not buying more items than needed (this is not allowed by definition)
            if(noNegativeNeed(needs)){
                //Calculate the best price with the current offer by adding the offer's value and recursing with the updated needs.
                int withOffer=offer.back()+shoppingOffers(price,special,needs);
                bestPrice=min(bestPrice,withOffer);
            }
            //Backtrack by adding the offer back to the needs.
            addOffer(offer,needs);
        }

        return state[needs]=bestPrice;
    }
};
