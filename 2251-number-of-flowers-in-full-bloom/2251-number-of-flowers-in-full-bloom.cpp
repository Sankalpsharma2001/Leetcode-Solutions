class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
       map<int,int> mp;
        mp[0]=0;
        for(auto &it:flowers)
        {
            mp[it[0]]++;
            mp[it[1]+1]--;
        }
        vector<int> prefix,pos;
        int sum=0;
        for(auto &it:mp)
        {
            pos.push_back(it.first);
            sum+=it.second;
            prefix.push_back(sum);
        }
        
        vector<int> ans;
        for(auto &it:people)
        {
            auto v=upper_bound(pos.begin(),pos.end(),it)-pos.begin();
            ans.push_back(prefix[v-1]);
        }
        return ans;
        
        
    }
};