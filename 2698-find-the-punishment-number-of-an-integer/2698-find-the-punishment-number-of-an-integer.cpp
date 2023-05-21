#define ll long long
class Solution {
public:
    bool solve(string s,int i,int sum,int no)
    {
        if(i==s.size() )
        {
           if( sum==no)
            return true;
            
            return false;
        }
         for(int j=i;j<s.size();j++)
        {
            string a=s.substr(i,j+1-i);
          
            if(solve(s,j+1,sum+stoi(a),no)) return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            int x=i*i;
            
            string s=to_string(x);
          
            if(solve(s,0,0,i))
            {
                ans+=x;
            }
        }
        return ans;
    }
};