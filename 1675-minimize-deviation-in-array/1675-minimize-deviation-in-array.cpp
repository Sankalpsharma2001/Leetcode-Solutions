class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n=nums.size();
        set<int> s;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2)
                s.insert(nums[i]*2);
            else
                s.insert(nums[i]);
        }
        int ans=*s.rbegin()-*s.begin();
        while((*s.rbegin())%2==0)
        {
            int val=*s.rbegin();
            s.erase(val);
            s.insert(val/2);
            
            ans=min(ans,(*s.rbegin()-*s.begin()));
        }
        return ans;
    }
    
};