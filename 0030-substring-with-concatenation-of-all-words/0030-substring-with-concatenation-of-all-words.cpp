class Solution {
public:
    bool check(unordered_map<string, int> wordCount,string s,int len)
    {
        for(int i=0;i<s.size();i+=len)
        {
            string str=s.substr(i,len);
            if(wordCount.find(str)!=wordCount.end())
            {
                wordCount[str]--;
                if(wordCount[str]<0)
                    return false;
                
            }
            else
                return false;
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int len=words[0].size();
        int windowSize=words.size()*len;
        int n=s.size();
        unordered_map<string, int> wordCount;
        for(auto &it:words)
        {
            wordCount[it]++;
        }
        int i=0;
        while(i+windowSize<=n)
        {
            if(check(wordCount,s.substr(i,windowSize),len))
            {
                ans.push_back(i);
            }
            i++;
        }
        return ans;
        
    }
};