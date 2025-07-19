class Solution {

  public:
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        int sum =0;
        for(auto it : arr) sum+=it;
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
        for (int i =0;i<=n;i++)
        {
            dp[i][0]=true ;
        }
        for(int i =1;i<=n;i++)
        {
            for(int j =0;j<=sum;j++){
                // not include 
                if (arr[i-1]>j)
                {
                    dp[i][j]= dp[i-1][j];
                }
                else if (j>=arr[i-1])
                {
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
            }
        }
        int diff = INT_MAX;
        for(int i =0;i<=sum/2;i++)
        {
            int first = i;
            int second = sum-i;
            if(dp[n][i]==true && diff>abs(first -second))
            {
                diff = abs(first -second);
            }
        }
        return diff;
        
    }
};
