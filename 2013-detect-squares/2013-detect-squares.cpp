class DetectSquares {
public:
    vector<vector<int>> p;
    
    DetectSquares() {
        for(int i = 0; i<1001; i++) {
            vector<int> temp(1001, 0);
            p.push_back(temp);
        }
    }
    
    void add(vector<int> point) {
        p[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int res = 0;
        int x = point[0], y = point[1];
        for(int len = 1; len < 1001; len++) {
            if(y + len <= 1000) {
                //First Quadrant
                if(x + len <= 1000) res += (p[x][y+len]*p[x+len][y]*p[x+len][y+len]);
                //Second Quadrant
                if(x - len >= 0) res += (p[x][y+len]*p[x-len][y]*p[x-len][y+len]);
            }
            if(y - len >= 0) {
                //Fourth Quadrant
                if(x + len <= 1000) res += (p[x][y-len]*p[x+len][y]*p[x+len][y-len]);
                //Third Quadrant
                if(x - len >= 0) {res += (p[x][y-len]*p[x-len][y]*p[x-len][y-len]);
            }
        }
        }
        return res;
        
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */