class Solution {
public:
    vector<string> solve(int n)
    {
        if(n==1)
            return {"0","1"};
        vector<string> v=solve(n-1);
        vector<string> x;
        for(int i=0;i<v.size();i++)
        {
            x.push_back("0"+v[i]);
        }
        for(int i=v.size()-1;i>=0;i--)
        {
            x.push_back("1"+v[i]);
        }
        return x;
    }
    int help(string &s)
    {
        int val=0,j=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            val+=(pow(2,j++)*(s[i]-'0'));
        }
        return val;
    }
    vector<int> grayCode(int n) {
  vector<int> ans;
        vector<string> v=solve(n);  
        for(auto x:v)
        {
            int r=help(x);
 ans.push_back(r);
            // ans.push_back(stoi(x , 0 , 2));
        }
        return ans;
    }
};