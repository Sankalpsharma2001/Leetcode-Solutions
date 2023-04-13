class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0;
        stack<int> st;
        int n=pushed.size();
        for(int j=0;j<n;j++)
        {
            if(pushed[j]==popped[i])
            {
                i++;
                while(!st.empty() && i<n && popped[i]==st.top())
                {
                    st.pop();
                    i++;
                }
            }
            else
            {
                st.push(pushed[j]);
            }
        }
        while(!st.empty() && i<n && popped[i]==st.top())
        {
            i++;
            st.pop();
        }
        return st.empty()?true:false;
    }
};