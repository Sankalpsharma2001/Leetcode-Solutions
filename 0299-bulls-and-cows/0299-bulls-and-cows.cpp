class Solution {
public:
    string getHint(string secret, string guess) {
        int x=0,y=0;
        unordered_map<int,int> m;
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i]==guess[i])
                x++;
            else
            m[secret[i]]++;
        }
        for(int i=0;i<guess.size();i++)
        {
             if(secret[i]==guess[i]) continue;
            if(m.find(guess[i])!=m.end())
            {
                m[guess[i]]--;
                if(m[guess[i]]==0) m.erase(guess[i]);
                y++;
            }
        }
        string ans=to_string(x)+"A"+to_string(y)+"B";
        return ans;
    }
};