//{ Driver Code Starts
// Initial Template for C++
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>& arr, int sum) {
          vector<int> ans;
    int i = 0, j = 0;
    int curr_sum = 0;
    int n = arr.size();
          if(sum==0){
               return{};
           }

    while (j < n) {
        curr_sum += arr[j];

        while (curr_sum > sum && i <= j) {
            curr_sum -= arr[i];
            i++;
        }

        if (curr_sum == sum) {
            ans.push_back(i + 1);
            ans.push_back(j + 1);
            return ans;
        }

        j++;
    }

    return {};
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        int sum;
        cin >> sum;
        cin.ignore();

        Solution sln;
        vector<int> list = sln.subarraySum(arr, sum);
        if (list.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : list)
                cout << i << " ";
            cout << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends