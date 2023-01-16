class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        vector<int> v={1,2,3,4,5,6,7,8,9};
        while(--n)
        {
            vector<int> v1;
            for(int i=0;i<v.size();i++)
            {
                
                int y=v[i]%10;
                if(y+k<10)
                {
                    v1.push_back(v[i]*10+y+k);
                }
                 if(k>0 && y-k>=0)
                {
                    v1.push_back(v[i]*10+y-k);
                }
            }
            v=v1;
        }
        
        return v;
        
    }
};