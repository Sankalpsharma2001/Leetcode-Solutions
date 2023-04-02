class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
     vector<int> res;
        int n=spells.size();
        sort(potions.begin(),potions.end());
        for(int i=0;i<n;i++)
        {
           int low=0,high=potions.size()-1,ans=-1;
           while(low<=high)
           {
               int mid=low+(high-low)/2;
               long long val=1ll*spells[i]*potions[mid];
               if(val>=success)
               {
                   ans=mid;
                  high=mid-1;
               }
               else
               {
                  low=mid+1;
               }
           }
            if(ans==-1)
            {
             res.push_back(0);   
            }
            else
            {
                res.push_back(potions.size()-ans);
            }
        }
        return res;
    }
};