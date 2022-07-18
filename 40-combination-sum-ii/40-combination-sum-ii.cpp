class Solution {
public:
 vector<vector<int>> ans;
 void help(vector<int>& candidates,int idx,vector<int> &v,int target,int s)
 {   
     if(s>target)
         return;
     if(target==s)
     {
         ans.push_back(v);
         return;
     }
      
    for(int i=idx;i<candidates.size();i++)
    {
        if(i!=idx and candidates[i]==candidates[i-1]) continue;
        
        v.push_back(candidates[i]);
            help(candidates,i+1,v,target,s+candidates[i]);
            v.pop_back();
        
       
    }
 }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<int> v;
        sort(candidates.begin(),candidates.end());
      
        help(candidates,0,v,target,0);
        return ans;
        
    }
};