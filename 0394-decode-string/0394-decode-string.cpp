class Solution {
public:
    string decodeString(string s) {
       stack<char> st;
       
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=']')
            {
                st.push(s[i]);
            }
            else
            {
                string res="";
                while(st.top()!='[')
                {
                    res=st.top()+res;
                    st.pop();
                }
                st.pop();
                string no="";
                while(!st.empty() and isdigit(st.top()))
                {
                    no=st.top()+no;
                    st.pop();
                    
                }
                int n=stoi(no);
                while(n--)
                {
                    for(int i=0;i<res.size();i++)
                    {
                        st.push(res[i]);
                    }
                }
                    
            }
        }
         string ans="";
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};