class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        if(n<0)
        {
            x=1/x;
            n=abs(n);
        }
        
        while(n)
        {
            if(n%2)
            {
                ans*=x;
               
            }
             x=x*x;
                n/=2;
            
        }
        return ans;
    }
};