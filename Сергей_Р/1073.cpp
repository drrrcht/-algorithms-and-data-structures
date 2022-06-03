#include <bits/stdc++.h>
#define ALGO for (int i = 3; i <= n; ++i) {dp[i] = i;for (int j = 1; j*j <= i; ++j)dp[i] = min(dp[i], 1 + dp[i - j*j]);}
#define pf cout << dp[n];
#define sf cin  >> n;
using namespace std;

vector<int> dp(60006);

int main() {
    int n;
    sf
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    ALGO pf
    return 0;
}
