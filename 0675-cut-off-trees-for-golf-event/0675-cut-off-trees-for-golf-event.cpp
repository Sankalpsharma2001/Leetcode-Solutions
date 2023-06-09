class Solution {
public:
   
      int BFS(vector<vector<int>> &forest, int &sX, int &sY, int &dX, int &dY){
        int n=forest.size();
        int m=forest[0].size();
        int X[4]={1,-1,0,0};
        int Y[4]={0,0,1,-1};
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        q.push({sX,sY});
        vis[sX][sY]=true;
        int res=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto curr=q.front();
                q.pop();
                int x=curr.first;
                int y=curr.second;
                if(x==dX && y==dY){
                    return res;
                }
                for(int dir=0;dir<4;dir++){
                    int newX=x+X[dir];
                    int newY=y+Y[dir];
                    if(newX<0 || newY<0 || newX==n || newY==m || forest[newX][newY]==0 || vis[newX][newY]==true){
                        continue;
                    }
                    vis[newX][newY]=true;
                    q.push({newX,newY});
                }
            }
            res++;
        }
        return -1;
          
      }
    
    int cutOffTree(vector<vector<int>>& forest) {
     
//         Our start point will always be (0,0) but we wanna cut off the smallest tree first of all, so we try to find the walk count from 0,0 to the shortest tree height index, and then we make this tree index as our start index for the next greater tree height and continue on and on

// If you are standing in a cell with a tree, you can choose whether to cut it off.
        int n=forest.size();
        int m=forest[0].size();
        vector<vector<int>> trees;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(forest[i][j]>1){
                    trees.push_back({forest[i][j],i,j});
                }
            }
        }
        sort(trees.begin(),trees.end());
        int res=0;
        int startX=0;
        int startY=0;
        for(auto &tree: trees){
            int treeX=tree[1];
            int treeY=tree[2];
            int distance=BFS(forest,startX,startY,treeX,treeY);
            if(distance==-1){
                return -1;
            }
            res+=distance;
            startX=treeX;
            startY=treeY;
        }
        return res;
    }
};