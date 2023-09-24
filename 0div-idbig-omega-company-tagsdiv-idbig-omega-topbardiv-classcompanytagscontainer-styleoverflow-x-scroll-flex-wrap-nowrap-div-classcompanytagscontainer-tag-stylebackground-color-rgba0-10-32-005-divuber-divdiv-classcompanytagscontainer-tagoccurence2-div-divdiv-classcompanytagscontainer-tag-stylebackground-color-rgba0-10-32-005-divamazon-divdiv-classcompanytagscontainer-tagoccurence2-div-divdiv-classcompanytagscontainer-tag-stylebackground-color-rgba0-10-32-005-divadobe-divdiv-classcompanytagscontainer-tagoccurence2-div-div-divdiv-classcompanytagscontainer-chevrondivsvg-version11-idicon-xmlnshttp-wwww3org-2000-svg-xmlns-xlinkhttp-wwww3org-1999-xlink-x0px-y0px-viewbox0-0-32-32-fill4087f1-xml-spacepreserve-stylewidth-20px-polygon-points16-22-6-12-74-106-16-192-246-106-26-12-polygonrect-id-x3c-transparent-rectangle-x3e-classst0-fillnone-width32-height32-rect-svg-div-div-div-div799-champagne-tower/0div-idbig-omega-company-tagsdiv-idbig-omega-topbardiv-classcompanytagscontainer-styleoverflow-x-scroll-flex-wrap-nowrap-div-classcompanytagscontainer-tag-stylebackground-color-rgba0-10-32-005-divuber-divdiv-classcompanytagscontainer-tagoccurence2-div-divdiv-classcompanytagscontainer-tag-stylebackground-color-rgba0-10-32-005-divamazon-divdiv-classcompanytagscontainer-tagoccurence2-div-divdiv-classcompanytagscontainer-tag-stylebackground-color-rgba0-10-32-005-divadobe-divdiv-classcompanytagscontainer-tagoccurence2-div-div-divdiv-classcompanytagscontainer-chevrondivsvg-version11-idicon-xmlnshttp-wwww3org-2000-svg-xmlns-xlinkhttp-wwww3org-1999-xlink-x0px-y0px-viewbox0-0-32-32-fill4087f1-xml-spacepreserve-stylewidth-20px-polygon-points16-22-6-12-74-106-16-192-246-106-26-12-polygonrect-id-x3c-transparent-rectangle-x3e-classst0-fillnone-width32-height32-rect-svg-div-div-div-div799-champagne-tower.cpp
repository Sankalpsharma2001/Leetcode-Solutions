class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> row(1,poured);
        for(int i=0;i<=query_row;i++)
        {
            vector<double> v(i+2,0);
            for(int j=0;j<=i;j++)
            {
                if(row[j]>=1)
                {
                    v[j]+=(row[j]-1)/2;
                    v[j+1]+=(row[j]-1)/2;
                    row[j]=1;
                }
            }
            if(i!=query_row)
            row=v;
        }
        return row[query_glass];
    }
};