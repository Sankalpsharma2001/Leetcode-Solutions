#define ll long long
class Solution {
public:
    int divide(int dividend, int divisor) {
         if(dividend==divisor)
             return 1;
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        if(dividend==INT_MIN && divisor==1) return INT_MIN;

        bool pos=true;
        if((dividend>0 and divisor<0) or (dividend<0 and divisor>0))                  pos=false;
        
        ll int a = abs(dividend);
        ll int b = abs(divisor);
        ll int ans=0;
        while(a>=b)
        {
            ll t=1,x=b;
            while(x<=a-x)
            {
                x+=x;
                t+=t;
            }
            ans+=t;
            a-=x;
            // ll int q=0;
            // while(a>(b<<(q+1)))
            //     q++;
            // ans+=(1<<q);
            // a=a-(b<<q);
        }
       
        return (pos)?ans:-ans;
    }
};