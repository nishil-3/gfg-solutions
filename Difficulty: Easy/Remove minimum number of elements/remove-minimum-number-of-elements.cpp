//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int minRemove(int a[], int b[], int n, int m) {
        unordered_map<int,int> m1, m2;
        
        for (int i=0;i<n;i++)
        {
           m1[a[i]]++;
        }
     
      for (int i=0;i<m;i++)
        {
           m2[b[i]]++;
        }
        int cnt =0;
       for (auto it : m1)
       {
           if(m2.find(it.first)!=m2.end())
           {
              cnt+=min(it.second, m2[it.first ]);
           }
       }
        
        
        return cnt ;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int a[n], b[m];
        for (i = 0; i < n; i++) cin >> a[i];
        for (i = 0; i < m; i++) cin >> b[i];
        Solution obj;
        cout << obj.minRemove(a, b, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends