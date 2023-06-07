class Solution {
public:
    int minFlips(int a, int b, int c) {
       int ans=0;
        for(int i=0;i<32;i++)
        {
            long long int mask = (1 << i) ;
            int cc=((mask)&c)?1:0;
            int bb=((mask)&b)?1:0;
            int aa=((mask)&a)?1:0;
            if((aa|bb)==cc)
            {
                continue;
            }
            else 
            {
            //    cout<<aa<<" "<<bb<<" "<<cc<<endl;
                 if(aa==1 and bb==1 and cc==0)
                 ans+=2;
                 else
                 ans++;
            }
            cout<<ans<<" ";
        }
        return ans;   
    }
};