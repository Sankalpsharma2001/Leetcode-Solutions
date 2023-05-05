class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> st;
        st.insert('a');st.insert('e');st.insert('i');st.insert('o');st.insert('u');
        int i=0;
        int c=0,ans=0,j=0;
        for( j=0;j<k;j++)
        {
            c+=(st.find(s[j])!=st.end());
        }
        ans=max(ans,c);
        
        while(j<s.size())
        {
            c+=(st.find(s[j])!=st.end());
            c-=(st.find(s[i])!=st.end());
            ans=max(ans,c);
            j++;
            i++;
        }
        return ans;
    }
};