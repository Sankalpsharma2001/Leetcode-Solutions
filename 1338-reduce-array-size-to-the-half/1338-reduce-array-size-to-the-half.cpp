class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto x:arr)
            m[x]++;
        vector<int> x;
        for(auto it:m) x.push_back(it.second);
        sort(x.begin(),x.end(),greater<int>());
        int c=0;
        int sum=0;
        for(int i=0;i<x.size();i++)
        {
            sum+=x[i];
            c++;
            if(sum>=arr.size()/2)
            {
                return c;
            }
        }
        return c;
    }
};