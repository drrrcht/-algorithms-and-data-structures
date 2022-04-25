#include <bits/stdc++.h>


const int MAXN = 5010;

int n;
char s[MAXN];
int lcp[2][MAXN];

int main() {
    gets(s);
    n = strlen(s);
    int ans = n * (n + 1) / 2;
    int idx = 0;
    for (int i = n - 1; i >= 0; i--) {
        int k = n - 1;
        while(k >= 0) {
            (s[i] == s[k])?lcp[idx][k] = lcp[idx ^ 1][k + 1] + 1:lcp[idx][k] = 0;
            k--;
        }

        int maxlen = 0;
        int j = i + 1;
        while ( j < n) {
            maxlen = std::max(maxlen, lcp[idx][j]);
            j++;
        }

        ans -= maxlen;
        idx ^= 1;
    }

    printf("%d\n", ans);

    return 0;
}
