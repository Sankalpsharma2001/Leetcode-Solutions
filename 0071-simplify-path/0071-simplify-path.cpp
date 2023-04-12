class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n=path.size();
        for(int i=0;i<n;i++)
        {
            if(path[i]=='/') continue;
            string str="";
            while(i<n && path[i]!='/')
            {
                str+=path[i++];
            }
            if(str==".") continue;
            if(str=="..") {
                if(!st.empty()) st.pop();
            }
            else
            {
                st.push(str);
            }
        }
        
        string ans="";
        while(!st.empty() )
        {
            ans="/"+st.top()+ans;
            st.pop();
        }
        return ans.size()?ans:"/";
        
    }
};