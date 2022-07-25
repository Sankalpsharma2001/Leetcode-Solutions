class Solution {
public:
    string convert(string s, int numRows) {
       ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int j=0;
        int n=s.size();
        vector<string> ans(numRows);
        
        while(j<n)
        {
            for(int i=0;j<n and i<numRows;i++)
            {
                ans[i]+=s[j++];
            }
            for(int i=numRows-2;j<n and i>0;i--)
            {
                ans[i]+=s[j++];
            }
        }
        string res="";
        for(int i=0;i<numRows;i++)
        {
         res+=ans[i];   
        }
        return res;
    }
};