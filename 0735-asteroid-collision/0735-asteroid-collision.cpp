class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
      vector<int> ans;
        for(auto &it:asteroids)
        {
            bool flag=true;
            while(ans.size() && ans.back()>0 && it<0 && flag)
            {
                if(ans.back()>-it)
                {
                    flag=false;
                }
                else if(ans.back()==-it)
                {
                    flag=false;
                    ans.pop_back();
                }
                else
                {
                    ans.pop_back();
                }
            }
            if(flag) ans.push_back(it);
        }
        return ans;
    }
};