#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

template <class type1>
using ordered_multiset = tree <type1, null_type, less_equal <type1>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
       ordered_multiset <ll> o_set;
        
        int n=nums.size();
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--)
        {
            o_set.insert(nums[i]);
            ans[i]=o_set.order_of_key(nums[i]);
        }
        return ans;
    }
};