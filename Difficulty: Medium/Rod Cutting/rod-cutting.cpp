// User function Template for C++

class Solution {
  public:
  int ans (int index, int n , vector<int>&price,  vector<vector<int>>& dp)
  {
      if (index ==0) return n*price[0];
      if(dp[index][n]!=-1) return dp[index][n];
      int nottake = 0+ ans(index-1,n,price,dp);
      int take = INT_MIN;
      int rodlen = index+1;
      if(rodlen <= n)
      {
          take = price[index] + ans(index,n-rodlen,price,dp);
      }
      return dp[index][n] = max(take,nottake);
      

  }
    int cutRod(vector<int> &price) {
        // code here
        // momeisation 
        int n = price.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return ans (n-1,n,price,dp);
        
    }
};