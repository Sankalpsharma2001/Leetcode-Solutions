class Solution
{
    public:
        int dp[1001][30][30] = {};
    int solve(vector<string> &words, int i, char firstChar, char lastChar)
    {
        if (i >= words.size()) return 0;
        if (dp[i][firstChar - 'a'][lastChar - 'a'] != -1) return dp[i][firstChar - 'a'][lastChar - 'a'];
        int res = INT_MAX, wordSize = words[i].size();
        if (words[i].back() == firstChar) res = min(res, wordSize - 1 + solve(words, i + 1, words[i][0], lastChar));
        else res = min(res, wordSize + solve(words, i + 1, words[i][0], lastChar));
        if (words[i][0] == lastChar) res = min(res, wordSize - 1 + solve(words, i + 1, firstChar, words[i].back()));
        else res = min(res, wordSize + solve(words, i + 1, firstChar, words[i].back()));
        return dp[i][firstChar - 'a'][lastChar - 'a'] = res;
    }
    int minimizeConcatenatedLength(vector<string> &words)
    {
        memset(dp,-1,sizeof(dp));
        return words[0].size() + solve(words, 1, words[0][0], words[0].back());
    }
};