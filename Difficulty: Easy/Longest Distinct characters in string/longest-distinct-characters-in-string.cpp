//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    // your code here
    int n = S.size();
    int maxlen =0;
    
    for (int i =0;i<n;i++)
    {
        char hash [256]= {0};
        for(int j =i;j<n;j++)
        {
            if (hash[S[j]]==1) break;
            hash [S[j]]=1;
            int len = j-i+1;
            maxlen = max(maxlen,len);
        }
    }
    return maxlen;
    
}