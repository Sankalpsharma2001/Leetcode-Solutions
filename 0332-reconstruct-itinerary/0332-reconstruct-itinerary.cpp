class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> ans;
        unordered_map<string,multiset<string>> adj;
        int n=tickets.size();
        for(int i=0;i<n;i++)
        {
            adj[tickets[i][0]].insert(tickets[i][1]);
        }
        stack<string> st;
        st.push("JFK");
        while(!st.empty())
        {
            string t=st.top();
           
            if(adj[t].size()==0)
            {
                ans.push_back(t);
               st.pop();     
            }
            else
            {
                auto x=adj[t].begin();
                st.push(*x);
                adj[t].erase(x);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};