class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size(),m=box[0].size();
        vector<vector<char>> ans(m,vector<char>(n));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(box[i][j]=='#')
                {
                    bool flag=false;
                    int idx=j;
                    for(int k=j+1;k<m;k++)
                    {
                        if(box[i][k]=='.')
                        {
                            flag=true;
                          idx=k;
                            
                        }
                        else if(box[i][k]=='*' || box[i][k]=='#')
                        {
                            

                            break;
                        }
                    }
                    if(flag && idx!=j)
                    {
                        box[i][j]='.';
                        box[i][idx]='#';
                    }
                }
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //         cout<<box[i][j]<<" ";
        //     cout<<endl;
        // }
        for(int i=0;i<n;i++)
        {
            for(int j=m-1;j>=0;j--)
            {
                ans[j][n-i-1]=box[i][j];
            }
        }
        return ans;
    }
};