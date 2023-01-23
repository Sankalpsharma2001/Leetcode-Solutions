class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st,st1; // st for (  , sr for * 
       
         int c=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(s[i]==')')
            {
                if(!st.empty())
                {
                    st.pop();
                }
                else if(!st1.empty())
                {
                    st1.pop();
                }
                else
                    return false;
            }
            else
            {
                st1.push(i);
            }
        }
        int open=0,close=0;
         // we have to check more no of * is in right side of ( when ( are more than close 
        while(!st.empty())
        {
            if(st1.empty())
            {
                return false;
            }
            else if(st.top()<st1.top())
            {
                st.pop();
                st1.pop();
            }
            else
                return false;
        }
       
            return true;
       
    }
};