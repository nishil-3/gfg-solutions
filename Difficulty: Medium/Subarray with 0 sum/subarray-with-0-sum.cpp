//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        // Your code here
       unordered_set <int> st ;
       int sum =0;
       for (int i =0;i<arr.size();i++)
       {
           sum+=arr[i];
           if (st.find(sum)!=st.end()) return true ;
           if (sum==0) return true ;
           
           st.insert(sum);
       }
       return false ;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        if (obj.subArrayExists(arr))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends