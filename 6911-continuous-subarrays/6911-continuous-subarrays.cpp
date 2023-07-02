#define ll long long
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
      multiset<int> a;
        int i=0,j=0;
      multiset<int,greater<int>> b;
        while(j<n)
        {
            a.insert(nums[j]);
            b.insert(nums[j]);
            while(*b.begin()-*a.begin()>2)
            {
                auto it=a.find(nums[i]);
                auto it1=b.find(nums[i]);
                a.erase(it);
                b.erase(it1);
                i++;
            }
            ans+=j-i+1;
            j++;
         }
        return ans;

    }
};