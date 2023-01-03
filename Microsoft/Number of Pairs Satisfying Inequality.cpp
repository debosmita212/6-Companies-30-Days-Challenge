//Leetcode 2426
/*
Learn about policy based datastructure- ordered_set(keeps the unique elements in sorted order)
provides extra two features
1. order_of_key (k) : Number of items strictly smaller than k .
2. find_by_order(k) : K-th element in a set (counting from zero).
*/
// Header files, namespaces,
// macros as defined above
/*
Rearranging the expression
nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff
nums1[i]-nums2[i]<= nums1[j]-nums2[j] + diff
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using pbds=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
  
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        pbds<pair<int,int>> s; //value,index  as value can appear more than once
        long long ans=0;
        for(int i=0;i<nums1.size();i++){
            int temp=nums1[i]-nums2[i]+diff;
            long long temp2=s.order_of_key({temp,INT_MAX});
            ans+=temp2;
            s.insert({nums1[i]-nums2[i],i});
        }
        return ans;

    }
};
