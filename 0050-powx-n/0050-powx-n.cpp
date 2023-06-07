#define ll long long
class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        ll n1=n;
        if(n1<0) n1*=-1;
        while(n1>0)
        {
            if(n1%2)
            {
                ans*=x;
                n1-=1;
            }
            else
            {
                x*=x;
                n1/=2;
            }
            
        }
        if(n<0) ans=1/ans;
        return ans;
    }
};