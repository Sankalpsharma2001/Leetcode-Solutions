//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int n,m;
    pair<int,int> dfs(int i,int j,int dir,vector<vector<int>> &matrix)
    {
        if(i<0 || j<0 || i==n || j==m)
        {
            if(i<0)
            {
                return {i+1,j};
                
            }
            if(j<0)
            {
                return {i,j+1};
            }
            if(i==n)
            {
                return {i-1,j};
            }
            if(j==m)
            {
                return {i,j-1};
            }
        }
        
        if(matrix[i][j]==0)
        {
            if(dir==1)
            {
              return dfs(i,j+1,dir,matrix);
                
            }
            if(dir==2)
            {
               return  dfs(i+1,j,dir,matrix);
            }
            if(dir==3)
            {
               return dfs(i,j-1,dir,matrix);
            }
            if(dir==4)
            {
               return dfs(i-1,j,dir,matrix);
            }
        }
        else
        {
            matrix[i][j]=0;
            if(dir==1)
            {
              return dfs(i+1,j,2,matrix);
                
            }
            if(dir==2)
            {
               return  dfs(i,j-1,3,matrix);
            }
            if(dir==3)
            {
               return dfs(i-1,j,4,matrix);
            }
            if(dir==4)
            {
               return dfs(i,j+1,1,matrix);
            }
            
            
        }
        
    }
    pair<int,int> endPoints(vector<vector<int>> matrix){
        //code here
         
         n=matrix.size();
         m=matrix[0].size();
         //1 right 2 down 3 left 4 up
        return dfs(0,0,1,matrix);
        
    }

};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends