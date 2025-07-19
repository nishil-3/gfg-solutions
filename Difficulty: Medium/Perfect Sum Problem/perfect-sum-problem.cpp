class Solution {
  public:
//   int check (vector<int>& arr,int n , int sum)
//   {
//       vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
//       for(int i=1;i<=sum;i++)
//       {
//           dp[0][i]=0;
//       }
//       for(int i=0;i<=n;i++)
//       {
//           dp[i][0]=1;
//       }
//       for(int i =1;i<=n;i++)
//       {
//           for(int j =1;j<=sum;j++)
//           {
//               if(arr[i-1]>j)
//               {
//                   // not pick 
//                   dp[i][j]=dp[i-1][j];
//               }
//               else if (j>=arr[i-1])
//               {
//                   dp[i][j]= dp[i-1][j]+dp[i-1][j-arr[i-1]];
//               }
//           }
//       }
//       return dp[n][sum];
//   }

int check(vector<int> &arr, int target) {

    // Get the size of the input array
    int n = arr.size();

    // Create a 2D DP table with dimensions (n+1) x (target+1)
    // dp[i][j] represents the number of ways to achieve a sum 'j'
    // using the first 'i' elements of the array
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    // Base case: There's exactly one way to achieve a
    // sum of 0 (by selecting no elements)
    dp[0][0] = 1;

    // Fill the DP table
    for (int i = 1; i <= n; i++) {

        for (int j = 0; j <= target; j++) {

            // First, consider excluding the current element
            dp[i][j] = dp[i - 1][j];

            // Then, consider including the current element
            // (if the remaining sum allows it)
            if (j >= arr[i - 1]) {
                dp[i][j] += dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    // Return the number of ways to achieve the
    // target sum using all elements in the array
    return dp[n][target];
}
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        return check (arr,target);
        
        
    }
};