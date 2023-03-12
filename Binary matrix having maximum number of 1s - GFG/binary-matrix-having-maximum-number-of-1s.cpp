//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int BinarySearch(vector<int>&mat)

    {

        int count = 0 ;

        int low = 0 ;

        int high = mat.size()-1 ;

        while(low <= high)

        {

            int mid = (low + high ) / 2 ;

            if(mat[mid] == 1 )

            {

                count += ( high - mid + 1 ) ;

                high = mid - 1 ; 

            }

            else

            {

                low = mid + 1 ;

            }

        }

        return count ;

    }

    vector<int> findMaxRow(vector<vector<int>> mat, int N) 

    {

        // vector<int>ans ;

        // int max1count = 0 ;

        // int maxRowNo ;

        // for(int r = 0 ; r < N ; r++)

        // {

        //     int low = 0 ;

        //     int high = N-1 ;

        //     int maxCount = BinarySearch(mat[r]);   // Time Complexity  nlog(n) 

        //     if(max1count < maxCount)

        //     {

        //         max1count = maxCount ;

        //         maxRowNo = r ;

        //     }

        // }

        // ans.push_back(maxRowNo) ;

        // ans.push_back(max1count) ;

        // return ans ;
          int row = 0, i = 0, j = N - 1;
        for (; i < N; i++) {
            while (mat[i][j] == 1 && j >= 0) {
                row = i;
                j--;
            }
        }
        return {row, N - 1 - j}; 

    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends