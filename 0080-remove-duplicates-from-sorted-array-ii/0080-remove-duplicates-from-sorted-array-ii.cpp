class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // O(N) time and space
        vector<int> v;
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
            if(m[nums[i]]>2) continue;
            v.push_back(nums[i]);
        }
        nums=v;
        return v.size();
    }
};