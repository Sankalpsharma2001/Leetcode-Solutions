class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i])!=m.end())
            {
                vector<int> a;
                a.push_back(i);
                a.push_back(m[target-nums[i]]);
                return a;
            }
            m[nums[i]]=i;
        }
        return {};
    }
};