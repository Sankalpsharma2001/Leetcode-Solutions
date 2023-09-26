class Solution {
public:
    string removeDuplicateLetters(string s) {
       vector<int> last(26,0);
        for(int i=0;i<s.size();i++)
        {
            last[s[i]-'a']=i;
        }
        vector<bool> vis(26,false);
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(vis[s[i]-'a']) continue;
            while(!st.empty() && st.top()>s[i] && i<last[st.top()-'a'])
            {
                vis[st.top()-'a']=false;
                st.pop();
            }
            st.push(s[i]);
            vis[s[i]-'a']=true;
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