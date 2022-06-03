#include <cstdio>
#define FULL_ALL for(int base, n; scanf("%d %d", &n, &base) == 2; )
#define FULL_I for(int m = 0; m < base; ++m) dp[0][m] = m>0;
#define pf printf("%d\n", ans);
#define FULL_ANS for(int i = 0; i < base; ++i) ans += dp[n-1][i];

int dp[20][10];
int main(void){
    FULL_ALL{
        FULL_I
        int i = 1;
        while( i < n) {
            int j = 0;
            while(j < base) {
                dp[i][j] = 0;
                int k = j == 0;
                while(k < base) {
                    dp[i][j] += dp[i - 1][k];
                    ++k;
                }
                ++j;
            }
            ++i;
        }
        int ans = 0;
        FULL_ANS pf
    }
    return 0;
}
