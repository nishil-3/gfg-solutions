class Solution {
  public:
bool answer(vector<int>arr,int n, int target){
    vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));
    for(int i =0;i<=n;i++)
    {
        dp[i][0]=true;
    }
       for(int i =1;i<=target;i++)
    {
        dp[0][i]=false;
    }
    for(int i =1;i<=n;i++)
    {
        for(int j =1;j<=target;j++)
        {
            if (j<arr[i-1])
            {
                // not pick 
                dp[i][j]=dp[i-1][j];
            }
            else if (j>=arr[i-1])
            {
                // pick and not pick 
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
    }
        return dp[n][target];
}
    bool isSubsetSum(vector<int>& arr, int sum) {
      int n =arr.size();
        return answer(arr,n,sum);
        
        
        
    }
};