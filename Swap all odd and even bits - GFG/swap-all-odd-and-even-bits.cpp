//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
    {
    	// Your code here
    	for(int i=0;i<32;i+=2)
    	{
    	    int ith=(n>>i)&1;
    	    int ith_1=(n>>(i+1))&1;
    	    n=n-(ith<<i)-(ith_1<<(i+1))+(ith<<(i+1))+(ith_1<<i);
    	}
    	return n;
    	
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;//testcases
	while(t--)
	{
		unsigned int n;
		cin>>n;//input n
		
		Solution ob;
		//calling swapBits() method
		cout << ob.swapBits(n) << endl;
	}
	return 0;
}
// } Driver Code Ends