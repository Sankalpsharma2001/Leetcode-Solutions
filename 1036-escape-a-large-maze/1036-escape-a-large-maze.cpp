class Solution {
public:
    bool isValid(int x,int y)
    {
        return x>=0 && y>=0  && x<1e6 && y<1e6;
    }
    bool canReach(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target)
    {
         set<pair<int,int>> block;
        for(auto &it:blocked)
        {
            block.insert({it[0],it[1]});
        }
         int maxArea=block.size()*(block.size()-1)/2;
        int currArea=1;
        if(block.size()==0) return true;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,-1,1};
        queue<pair<int,int>> q;
        q.push({source[0],source[1]});
        set<pair<int,int>> vis;
        vis.insert({source[0],source[1]});
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            int x=f.first;
            int y=f.second;
            for(int i=0;i<4;i++)
            {
                int newX=x+dx[i];
                int newY=y+dy[i];
                if(newX==target[0] && newY==target[1]) return true;
                if(currArea>maxArea) return true;
                if(isValid(newX,newY) && vis.find({newX,newY})==vis.end() && block.find({newX,newY})==block.end())
                {
                    currArea++;
                    vis.insert({newX,newY});
                    q.push({newX,newY});
                }
            }
            
            
        }
        return false;
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        return canReach(blocked,source, target) && canReach(blocked,target,source);
       
    }
};