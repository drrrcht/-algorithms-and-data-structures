#include <bits/stdc++.h>
static long Calculate(int n, int k){
  int * dp = new int [17];
  dp[0] = 1;
  dp[1] = k - 1;
  for (int i = 2; i <= n; i++){
    dp[i] = dp[i - 1] * (k - 1) + dp[i - 2] * (k - 1);
  }
  return dp[n];       
}
int main(){
  int n,k;
  std::cin>>n>>k;
  std::cout<<Calculate(n, k);
}



