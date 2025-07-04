//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maximumSumSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int l =0;
        int r = 0;
        int sum = 0;
        int maxi = 0;
        while (r<n)
        {
            sum+=arr[r];
            if (r-l+1 < k) r++;
            else if(r-l+1 == k)
            {
                maxi = max(maxi,sum);
                sum-=arr[l];
                l++;
                r++;
            }
        }
        return maxi ;
        
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        int ans = ob.maximumSumSubarray(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends