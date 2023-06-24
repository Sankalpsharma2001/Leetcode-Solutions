class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
         vector<pair<int,int>> qs;
        
        for(int i=0; i<queries.size(); i++) {
            qs.push_back({queries[i], i});
        }
        
        sort(qs.begin(), qs.end());
        
        set<pair<int,int>> s;
        map<int,int> count;
        
        sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        
        vector<int> result(queries.size());
        int i = 0;
        
        for(auto& [q, ind] : qs) {
            while(i<logs.size() and logs[i][1]<=q) {
                s.insert({logs[i][1], logs[i][0]});
                count[logs[i][0]]++; // adding server id 
                i++;
            }
            
            while(!s.empty() and s.begin()->first < q-x) {
                count[s.begin()->second]--;
                
                if(count[s.begin()->second] == 0) {
                    count.erase(s.begin()->second);
                }
                
                s.erase(s.begin());
            }
            
            result[ind] = n - count.size();
        }
        
        return result;
    }
};