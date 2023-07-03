class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            unordered_set<int> st;
            int cnt=0;
            for(int j=i;j<n;j++)
            {
                int x=nums[j];
                if(st.count(x))
                {
                    
                }
                else if(!st.empty() && st.count(x-1) && st.count(x+1))
                {
                    cnt--;
                }
                else if(!st.empty() && !st.count(x-1) && !st.count(x+1))
                {
                    cnt++;
                }
                    
                st.insert(x);
                ans+=cnt;
            }
        }
        return ans;
    }
};