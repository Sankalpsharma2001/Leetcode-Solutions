
#define ll long long
class Solution
{
    public:
    void generate(int s, int e, int total, vector<int>& nums, vector<int>& sums){
        if(s==e){
            sums.push_back(total);
            return;
        }
        
        generate(s+1, e, total, nums, sums);        
        generate(s+1, e, total + nums[s], nums, sums);
    }
        vector<ll> get_subset_sums(vector<int> &nums, int l, int r)
        {
            int len = r - l + 1;
            vector<ll> res;

           	// loop through all subsets
            for (int i = 0; i < (1 << len); i++)
            {
                ll sum = 0;
                for (int j = 0; j < len; j++)
                {
                    if (i &(1 << j))
                    {
                        sum += nums[l + j];
                    }
                }
                res.push_back(sum);
            }

            return res;
        }
    int minAbsDifference(vector<int> &nums, int goal)
    {

        int n = nums.size();
        // generate(0,n/2-1,nums,left);
        // generate(n/2,n-1,nums,right);
        
        vector<ll> left = get_subset_sums(nums, 0, n / 2 - 1);
        vector<ll> right = get_subset_sums(nums, n / 2, n - 1);
        sort(right.begin(), right.end());
        int ans = INT_MAX;
        for (auto sum: left)
        {
            auto it = lower_bound(right.begin(), right.end(), goal - sum);
            if (it != right.end())
            {
                ans = min(ans, (int) abs(goal - (sum + *it)));
                auto it2 = it;
                it2++;
                if (it2 != right.end())
                    ans = min(ans, (int) abs(goal - (sum + *it2)));
            }
            if (it != right.begin())
            {
                ans = min(ans, (int) abs(goal - (sum + *(--it))));
            }
        }
        return ans;
    }
};