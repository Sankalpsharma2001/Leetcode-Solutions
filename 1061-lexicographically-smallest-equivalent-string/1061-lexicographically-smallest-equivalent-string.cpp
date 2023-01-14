class Solution {
public:
    
    vector<int> par;
    int find(int node)
    {
        if(node==par[node])
            return node;
        return par[node]=find(par[node]);
    }
    void Union(int x,int y)
    {
        x=find(x);
        y=find(y);
        if(x!=y)
        {
            if(x<y)
            {
                par[y]=x;
            }
            else
            {
                par[x]=y;
            }
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
       par.resize(26);
        for(int i=0;i<26;i++)
             par[i]=i;
        for(int i=0;i<s1.size();i++)
        {
            Union(s1[i]-'a',s2[i]-'a');
        }
        string ans="";
        for(char &c:baseStr)
        {
            ans+=find(c-'a')+'a';
        }
        return ans;
    }
};