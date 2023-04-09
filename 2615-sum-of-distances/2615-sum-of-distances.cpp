#define ll long long
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
      int n = nums.size();
        vector<long long>ans(n);
        unordered_map<int, vector<int>>mp;
        for (int i = 0; i < n; i++) mp[nums[i]].push_back(i);
        for (auto &it : mp)
        {
            int num = it.first;
            vector<int>& indexes = it.second;
            long long totalSum = 0;
            for (int &index : indexes) totalSum += (long long)index;
            
            long long preSum = 0;
            for (int i = 0; i < indexes.size(); i++)
            {
                int val = indexes[i];
                long long postSum = totalSum - preSum - val;
                
                ans[val] += (val * (long long)i);
                ans[val] -= (preSum);
                ans[val] -= (val * (long long)(indexes.size() - i - 1));
                ans[val] += (postSum);
                
                preSum += val;
            }
           }
        return ans;
    }
};