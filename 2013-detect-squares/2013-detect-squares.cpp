class DetectSquares {
public:
    vector<unordered_map<int, int>> x_axis;
    DetectSquares() {
         x_axis = vector<unordered_map<int, int>>(1005);
    }
    
    void add(vector<int> point) {
        int x=point[0],y=point[1];
        x_axis[x][y]++;
    }
    
    int count(vector<int> point) {
        int x=point[0],y=point[1];
        int ans=0;
        for(auto &it:x_axis[x])
        {
            int y1=it.first;
            int fre=it.second;
            if(y1==y) continue;
            int len=abs(y-y1);
            if(x+len<=1000)
            {
                int newX=x+len;
                ans+=(x_axis[x][y1]*x_axis[newX][y]*x_axis[newX][y1]);
            }
            if(x-len>=0)
            {
                int newX=x-len;
                 ans+=(x_axis[x][y1]*x_axis[newX][y]*x_axis[newX][y1]);
            }
        }
        return ans;
        
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */