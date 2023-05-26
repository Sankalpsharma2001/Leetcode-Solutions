class Solution {
public:
    
    string stoneGameIII(vector<int>& s) {
        int n=s.size();
        vector<int> dp(n+1,0);
        int i1=0,i2=0,i3=0;
        int i=n-1;
        while(i>=0)
        {
            int a,b,c;
            a=b=c=INT_MIN;
            a=s[i]-i1;
             if(i+1<s.size())
            b=s[i]+s[i+1]-i2;
             if(i+2<s.size())
            c=s[i]+s[i+1]+s[i+2]-i3;
            i3=i2;
            i2=i1;
            i1=max({a,b,c});
            i--;
        }
        int res=i1;
        if (res>0)
            return "Alice";
        if(res==0) return "Tie";
        return "Bob";
    }
};