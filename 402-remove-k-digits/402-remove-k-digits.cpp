class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        if(k>=n)
            return "0";
        stack<char> st;
      st.push(num[0]);
        for(int i=1;i<num.size();i++)
        {
            while(k>0 and !st.empty() and st.top()>num[i])
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
            if(st.size()==1 and num[i]=='0')
                st.pop();
        }
        while(k>0 and !st.empty())
        {
            k--;
            st.pop();
        }
    string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        if(ans=="")
            return "0";
        return ans;
    }
};