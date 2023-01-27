class Solution {
public:
    string ans="987654321";
    string smallestNumber(string pattern) {
        // BACKTRACKING
        // string s="";
        // vector<int> vis(10,0);
        // solve(pattern,vis,-1,s);
        // return ans;
        
        // Stack
         int n = pattern.size();
        
        stack<int> st;
        
        string num = "";
        
        for(int i=0; i<=n; i++) {
            st.push(i);
            
            if(i == n || pattern[i] == 'I') {
                while(st.size()) {
                    num += (st.top() + '1');
                    st.pop();
                }
            }
        }
        
        return num;
        
         // GREEDY
        // int n=pattern.size();
        // string ans="";
        // int j=0;
        // for(int i=0;i<=pattern.size();i++)
        // {
        //   ans+=('1'+i);
        //     if(i==pattern.size() || pattern[i]=='I')
        //     {
        //         reverse(ans.begin()+j,ans.end());
        //         j=i+1;
        //     }
        // }
        // return ans;
    }
    void solve(string &pattern,vector<int> &vis,int i,string s)
    {
        if(i==pattern.size())
        {
            if(ans>s)
            {
                ans=s;
            }
            return;
        }
        if(i==-1)
        {
            for(int j=1;j<=9;j++)
            {
                if(vis[j]==0)
                {
                    vis[j]=1;
                    s+=j+'0';
                    solve(pattern,vis,i+1,s);
                    s.pop_back();
                    vis[j]=0;
                }
            }
        }
        else
        {
            if(pattern[i]=='I')
            {
                int temp=s[s.size()-1]-'0';
                for(int j=temp+1;j<=9;j++)
                {
                    if(vis[j]==0)
                    {
                         vis[j]=1;
                    s+=j+'0';
                    solve(pattern,vis,i+1,s);
                    s.pop_back();
                    vis[j]=0;
                    }
                }
            }
            else
            {
                int temp=s[s.size()-1]-'0';
                 for(int j=temp-1;j>=1;j--)
                {
                    if(vis[j]==0)
                    {
                         vis[j]=1;
                    s+=j+'0';
                    solve(pattern,vis,i+1,s);
                    s.pop_back();
                    vis[j]=0;
                    }
                }
            }
        }
    }
};