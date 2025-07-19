class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int n = arr.size();
        int sum =0;
        for (auto it : arr) sum+=it;
         if ((sum + d) % 2 != 0 || sum < d) return 0;
        int total = (d+sum)/2;
        
        vector<vector<int>>dp(n+1,vector<int> (total+1,0));
        for(int i =0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        for(int i =1;i<=n;i++)
        {
            for(int j =0;j<=total;j++)
            {
                // not pick and pick
                if(arr[i-1]>j)
                {
                    dp[i][j]= dp[i-1][j];
                }
                else if (j>=arr[i-1])
                {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
                }
            }
        }
        return dp[n][total];
    }
};