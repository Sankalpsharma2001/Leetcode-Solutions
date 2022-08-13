class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else
            {
                if(!st.empty() and s[st.top()]=='(')
                {
                    st.pop();
                }
                else
                    st.push(i);
            }
        }
        int ans=INT_MIN;
        int x=s.size();
        while(!st.empty())
        {
            ans=max(ans,x-st.top()-1);
            x=st.top();
            st.pop();
        }
        ans=max(ans,x-0);
        return ans;
    }
};