class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long ans=1;
        vector<int>pos,neg;
        int zero=0;
        for(auto &num:nums)
        {
            if(num>0)
                pos.push_back(num);
            else if(num==0)
                zero=1;
            else
                neg.push_back(num);
        }
        for(auto &num:pos)
            ans=ans*num;
        
        sort(neg.begin(),neg.end());
        
        int n=pos.size();
        int m=neg.size();
        
        if(n==0)
        {
            if(neg.size()==1)
            {
                if(zero)
                    return 0;
                else
                    return neg[0];
            }
            else if(neg.size()==0)
                return 0;
                
        }
        if(m%2==1)
            m--;
        
        for(int i=0;i<m;i++)
            ans=ans*neg[i];
        
        return ans;
        
    }
};