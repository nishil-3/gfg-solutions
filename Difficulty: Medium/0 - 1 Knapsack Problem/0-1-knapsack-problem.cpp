class Solution {
  public:
  int answer(int W, vector<int> &val, vector<int> &wt, int n,   vector<vector<int>> &dp)
  {
      // tabulation code
      for (int i =0;i<=n;i++)
      {
          for(int j =0;j<=W;j++)
          {
              if(i==0 ||j==0) dp[i][j]=0;
              else if (wt[i-1]>j) dp[i][j]=dp[i-1][j];
              else dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][j-wt[i-1]]);
          }
      }
          return dp[n][W];
   
      
      
  }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>>mem(n+1, vector<int>(W+1,-1));
        return answer (W,val,wt,n,mem);
        
    }
};