class Solution {
public:
    bool check(string &s,int k,int mid)
    {
        int n=s.size();
        int i=0,j=0;
        unordered_map<char,int> mp;
        for(int i=0;i<mid;i++)
            mp[s[i]]++;
         if(min(mp['T'],mp['F'])<=k) return true;
        j=mid;
        while(j<n)
        {
           mp[s[j]]++;
            mp[s[i]]--;
            if(min(mp['T'],mp['F'])<=k) return true;
            i++;
            j++;
        }
        return false;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
        int low=k,high=n,ans=k;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(answerKey,k,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};