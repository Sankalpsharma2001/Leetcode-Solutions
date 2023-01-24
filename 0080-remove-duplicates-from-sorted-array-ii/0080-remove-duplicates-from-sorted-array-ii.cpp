class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int j=0,n=nums.size();
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
            if(m[nums[i]]>2) continue;
             nums[j++]=nums[i];
        }
        return j;
    }
};