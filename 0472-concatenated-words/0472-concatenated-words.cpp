class Solution {
public:
    int noOfConcatedStrings(string word, unordered_map<string, int> &dp, unordered_set<string> &uniqueWords) {
        if(word == "") return 0;
        
        // If we've already calculated the 
        //concatenated string count for current word, 
        //return the count
        if(dp.count(word)) return dp[word];
        
        int sz = word.length();
        string current = "";       // to form possible combination
        int mxCount = INT_MIN;     // count of smaller concatenated strings
        
        for(int i = 0; i < sz; i++) 
        {
            current += word[i];          // form the possible combination
            if(uniqueWords.count(current)) // does combination belongs to set of given words??
            {
                // increase count by 1 and find count for remaining word      
                mxCount = max(mxCount, 1 + noOfConcatedStrings(word.substr(i + 1), dp, uniqueWords)); 
                
            }
        }
        
        return dp[word] = mxCount;       // store count for current word
    }
 
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> uniqueWords;
        for(string &it:words) {
            uniqueWords.insert(it);
        }
        vector<string> ans;
        unordered_map<string,int> dp;
        for(auto &w:words)
        {
            int n=w.size();
            if(noOfConcatedStrings(w,dp,uniqueWords)>=2)
            {
                ans.push_back(w);
            }
        }
        return ans;
        
    }
};