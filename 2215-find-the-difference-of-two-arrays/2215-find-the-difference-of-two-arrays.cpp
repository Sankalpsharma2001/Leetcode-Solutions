
#define uniq(a) a.resize(unique(a.begin(), a.end()) - a.begin());
class Solution
{
    public:
        vector<vector < int>> findDifference(vector<int> &nums1, vector<int> &nums2)
        {
            unordered_set<int> a(nums1.begin(), nums1.end()), b(nums2.begin(), nums2.end());
            vector<vector < int>> ans(2);

            for (int it: a)
            {
                if (b.count(it) == 0) ans[0].push_back(it);
            }
            for (int it: b)
            {
                if (a.count(it) == 0) ans[1].push_back(it);
            }

            return ans;
        }
};