class Solution {
public:
    int passThePillow(int n, int time) {
      n--;
        int rem=time%n;
        int q=time/n;
        if(q%2)
        {
            return n-rem+1;
        }
        return rem+1;
        // int x=1;
        // bool flag=true;
        // while(time--)
        // {
        //     if(x==n && flag==true)
        //     {
        //         x--;
        //       flag=false;
        //         continue;
        //     }
        //     if(x==1 && !flag)
        //     {
        //         x++;
        //         flag=true;
        //         continue;
        //     }
        //     if(x<n+1 && flag)
        //     {
        //         x++;
        //         continue;
        //     }
        //     if(!flag && x>0)
        //     {
        //         x--;
        //         continue;
        //     }
        // }
        // return x;
    }
};