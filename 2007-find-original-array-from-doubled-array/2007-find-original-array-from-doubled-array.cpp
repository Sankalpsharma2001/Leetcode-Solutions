class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(),changed.end());
            if(changed.size()%2)
                return {};
        map<int,int> m;
        for(auto &it:changed)
            m[it]++;
        vector<int> ans;
        for(int i=0;i<changed.size();i++)
        {
            
            int ele=changed[i];
           if(m[ele]==0) continue;
               if(m[ele*2]==0)
                   return {};
                ans.push_back(ele);
            m[ele]--;
            m[2*ele]--;
            
        }
        return ans;
    }
};