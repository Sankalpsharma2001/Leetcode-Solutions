class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
       map<int,int> m1;
        for(auto &it:basket1)
        {
            m1[it]++;
           
        }
        for(auto &it:basket2)
        {
            m1[it]--;
          
        }
        vector<int> swap;
        int mn=m1.begin()->first;
        for(auto &it:m1)
        {
            int val=it.first;
            int fre=abs(it.second);
            if(fre%2) return -1;
            for(int i=0;i<fre/2;i++)
            {
                swap.push_back(val);
            }
            
        }
        long long ans=0;
        for(int i=0;i<swap.size()/2;i++)
        {
            ans+=min((int)swap[i],(int)2*mn);
        }
        return ans;
        
   }
};