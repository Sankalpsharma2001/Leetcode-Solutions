class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        multiset<vector<int>> mt;
        st.push(0);
        for(int i=1;i<n;i++)
        {
            while(!mt.empty() && nums[i]>(*mt.begin())[0])
            {
                ans[(*mt.begin())[1]]=nums[i];
                mt.erase(mt.begin());
            }
            while(!st.empty() && nums[i]>nums[st.top()])
            {
                mt.insert({nums[st.top()],st.top()});
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};