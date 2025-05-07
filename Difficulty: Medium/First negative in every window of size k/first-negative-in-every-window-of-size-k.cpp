//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        queue <int> q;
        vector<int> ans ;
        int left = 0, right = 0;
        int n =arr.size();
        while (right < n)
        {
            // calc 
            if (arr[right] < 0) q.push(arr[right]);
            if (right-left+1 < k) 
            {
                right++;
            }
            else if(right-left+1 == k)
            {
                if (q.empty() )ans.push_back(0);
                else {
                    ans.push_back(q.front());
                    if (q.front() == arr[left]) 
                    {
                        q.pop();
                    }
                }
                
                 left ++;
                        right ++;
            }
            
        }
        return ans ;
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
        vector<int> ans = ob.firstNegInt(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends