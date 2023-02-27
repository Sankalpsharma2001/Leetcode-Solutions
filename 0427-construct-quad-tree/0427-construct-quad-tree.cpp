/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool check(int x,int y,vector<vector<int>>& grid,int len)
    {
        for(int i=x;i<x+len;i++)
        {
            for(int j=y;j<y+len;j++)
            {
                if(grid[i][j]!=grid[x][y])
                    return false;
            }
        }
        return true;
    }
    Node *solve(int x,int y,vector<vector<int>>& grid,int len)
    {
        if(check(x,y,grid,len))
        {
            // If all elements in the quadrant are the same, create a new leaf node
            return new Node(grid[x][y],true);
        }
        else
        {
           // otherwise call all left quadrant 
           Node *topLeft=solve(x,y,grid,len/2);
           Node *topRight=solve(x,y+len/2,grid,len/2);
           Node *bottomLeft=solve(x+len/2,y,grid,len/2);
           Node *bottomRight=solve(x+len/2,y+len/2,grid,len/2);
           return new Node(false,false,topLeft,topRight,bottomLeft,bottomRight); 
        }
    }
    Node* construct(vector<vector<int>>& grid) {
        return solve(0,0,grid,grid.size());
    }
};