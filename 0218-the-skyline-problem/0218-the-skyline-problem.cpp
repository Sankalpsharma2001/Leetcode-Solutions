class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
          vector<pair<int, int>> walls;
        vector<vector<int>> ans;
        for(auto &b:buildings)
        {
            walls.push_back({b[0],-b[2]});
            walls.push_back({b[1],b[2]});
        }
        sort(walls.begin(),walls.end());
        multiset<int> leftWalls;
        int top=0;
        leftWalls.insert(0);
        for(auto &w:walls)
        {
            if(w.second<0)
            {
                leftWalls.insert(-w.second);
            }
            else
            {
                leftWalls.erase(leftWalls.find(w.second));
            }
            if(*leftWalls.rbegin()!=top)
            {
                top=*leftWalls.rbegin();
                ans.push_back({w.first,top});
            }
        }
        return ans;
        
        
    }
};