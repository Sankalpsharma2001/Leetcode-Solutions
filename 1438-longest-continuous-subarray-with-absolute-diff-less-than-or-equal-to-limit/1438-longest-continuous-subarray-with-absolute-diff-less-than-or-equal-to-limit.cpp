class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
          int n=nums.size();
        long long ans=0;
		 int i=0,j=0;
      multiset<int> a;
       
        while(j<n)
        {
            a.insert(nums[j]);
           
            while(*a.rbegin()-*a.begin()>limit)
            {
                auto it=a.find(nums[i]);
                a.erase(it);
             
                i++;
            }
            ans=max((1ll)*(j-i+1),ans);
            j++;
         }
        return ans;
    }
};