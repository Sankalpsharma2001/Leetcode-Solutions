class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int cnt=0;
        unordered_set<char> st(s.begin(),s.end());
        if(s.size()!=goal.size()) return false;
        if(s==goal &&  st.size()<goal.size()) return true;
        vector<int> v;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=goal[i]){v.push_back(i); cnt++;}
            if(cnt>2) return false;
        }
        return cnt==2 && s[v[1]]==goal[v[0]] && s[v[0]]==goal[v[1]];
    }
};