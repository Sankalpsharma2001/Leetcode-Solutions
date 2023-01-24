class Solution {
public:
   
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(),score.end(),[&](auto const &a,auto const &b){
            return a[k]>b[k];
        });
        return score;
        // int n=score.size(),m=score[0].size();
       //  vector<pair<int,int>> p;
       //  for(int i=0;i<n;i++)
       //  {
       //      p.push_back({score[i][k],i});
       //  }
       //  sort(p.rbegin(),p.rend());
       //  vector<vector<int>> ans;
       //  for(int i=0;i<p.size();i++)
       //  {
       //      int idx=p[i].second;
       //      vector<int> v;
       //      for(int j=0;j<m;j++)
       //      {
       //          v.push_back(score[idx][j]);
       //      }
       //      ans.push_back(v);
       //  }
       //  return ans;
    }
};