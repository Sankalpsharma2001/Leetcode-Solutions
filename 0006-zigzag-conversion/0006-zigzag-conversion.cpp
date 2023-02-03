class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> v(numRows);
        int n=s.size();
        int i=0;
        while(i<n)
        {
            for(int j=0;i<n && j<numRows;j++)
            {
               v[j]+=s[i++];    
            }
            for(int j=numRows-2;i<n && j>0;j--)
            {
                v[j]+=s[i++];
            }
            
        }
        string ans="";
        for(int i=0;i<numRows;i++)
        {
            ans+=v[i];
        }
        return ans;
    }
};