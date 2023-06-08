class Solution {
public:
    int getMinSwaps(string num, int k) {
        string src = num;
        int n=num.size();
        int ans = 0;
        for(int i = 0; i < k; i++) {
            next_permutation(num.begin(), num.end());
        }
        
    
        for(int i=0;i<n;i++)
        {
            int j=i;
            while(j<n && src[j]!=num[i]) j++;
            for(int l=j;l>i;l--)
            {
                ans++;
                swap(src[l],src[l-1]);
            }
        }
        return ans;
    }
};