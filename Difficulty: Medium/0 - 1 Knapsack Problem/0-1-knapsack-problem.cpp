class Solution {
  public:
  int answer(int W, vector<int> &val, vector<int> &wt, int index,   vector<vector<int>> &mem)
  {
      if (index == 0 || W ==0 ) return 0;
      if(mem[index][W]!= -1) return mem[index][W];
      // include and exclude 
      if (wt[index-1] > W)
      {
          mem[index][W]= answer (W,val,wt,index-1,mem);
      }
      else {
          mem[index][W] = max(answer(W,val,wt,index-1,mem), val[index-1] + answer(W-wt[index-1],val,wt, index-1,mem));
      }
      return mem[index][W];
  }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>>mem(n+1, vector<int>(W+1,-1));
        return answer (W,val,wt,n,mem);
        
    }
};