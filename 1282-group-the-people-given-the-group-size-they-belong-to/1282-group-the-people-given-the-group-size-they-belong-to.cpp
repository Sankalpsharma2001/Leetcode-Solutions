class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
         vector<vector<int>> ans;
        
        vector<vector<int>> freq(groupSizes.size()+1);
        for(int i=0;i<groupSizes.size();i++)
        {
            freq[groupSizes[i]].push_back(i);
            if(freq[groupSizes[i]].size()==groupSizes[i])
            {
                ans.push_back(freq[groupSizes[i]]);
                freq[groupSizes[i]].clear();
            }
        }
        return ans;
    }
};