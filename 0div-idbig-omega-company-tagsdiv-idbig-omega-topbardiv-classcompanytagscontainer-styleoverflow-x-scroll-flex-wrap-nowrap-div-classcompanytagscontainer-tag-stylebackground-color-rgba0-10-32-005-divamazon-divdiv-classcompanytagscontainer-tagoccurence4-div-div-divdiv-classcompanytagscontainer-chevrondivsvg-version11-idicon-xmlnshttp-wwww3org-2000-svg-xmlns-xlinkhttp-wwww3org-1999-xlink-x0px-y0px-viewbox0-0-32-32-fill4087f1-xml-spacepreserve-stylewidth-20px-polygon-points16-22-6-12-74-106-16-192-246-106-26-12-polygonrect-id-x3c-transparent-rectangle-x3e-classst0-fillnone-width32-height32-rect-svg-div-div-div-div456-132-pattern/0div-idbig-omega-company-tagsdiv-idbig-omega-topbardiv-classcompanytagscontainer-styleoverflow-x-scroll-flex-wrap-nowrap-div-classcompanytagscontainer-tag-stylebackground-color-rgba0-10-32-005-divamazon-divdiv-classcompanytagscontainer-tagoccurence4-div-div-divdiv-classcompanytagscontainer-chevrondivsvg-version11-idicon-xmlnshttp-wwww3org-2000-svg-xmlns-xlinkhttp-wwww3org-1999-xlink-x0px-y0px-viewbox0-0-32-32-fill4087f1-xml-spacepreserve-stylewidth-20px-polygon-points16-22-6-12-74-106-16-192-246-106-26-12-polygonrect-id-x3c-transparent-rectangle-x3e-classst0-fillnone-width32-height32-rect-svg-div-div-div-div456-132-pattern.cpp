class Solution {
public:
    bool find132pattern(vector<int>& nums) {
       int n=nums.size();
        int s2=INT_MIN;
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            if(s2>nums[i]) return true;
            while(!st.empty() && nums[i]>nums[st.top()])
            {
                s2=nums[st.top()];
                st.pop();
                
            }
            st.push(i);
        }
    return false;
        
    }
};