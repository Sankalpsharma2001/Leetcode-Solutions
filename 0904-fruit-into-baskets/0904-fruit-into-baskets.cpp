class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int left=0,right=0;
        map<int,int> m;
            int ans=0;
        for(right=0;right<n;right++)
        {
            m[fruits[right]]++;
            if(m.size()>2)
            {
                m[fruits[left]]--;
                if(m[fruits[left]]==0)
                {
                    m.erase(fruits[left]);
                }
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};