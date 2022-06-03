#include <bits/stdc++.h>

#define SZ(a) int((a).size())
#define pip a[u].emplace_back(II(v, c)); a[v].emplace_back(II(u, c));
#define cin std::cin
#define cout std::cout
#define posix_if if (q <= 0) return 0;if (dp[u][q] != -1) return dp[u][q];


const int MAXN = 110;
using ld = double;
typedef std::pair<int, int> II;
typedef std::pair<II, int> III;
typedef std::complex<ld> cd;
std::vector<II> a[MAXN];
int n, q, dp[MAXN][MAXN];


int solve(int u, int p, int q) {
    posix_if
    int x ;
    x= -1;
    int y;
    y= -1;
    for(int i= 0; i<= SZ(a[u])-1; ++i) {
        int v;
        v = a[u][i].first;
        if (v == p) continue;
        x == -1 ? x=i : y=i;
    }
    if (x == -1) return dp[u][q] = 0;
    int vX;
    vX = a[u][x].first;
    int cX;
    cX = a[u][x].second;
    int vY;
    vY= a[u][y].first;
    int cY;
    cY= a[u][y].second;
    int res = 0;
    for(int k=0; k<=q;++k) {
        int lef;
        lef= solve(vX, u, k-1);
        if (k > 0) lef = lef + cX;
        int rig;
        rig = solve(vY, u, q-k-1);
        if (k < q) rig =rig + cY;
        res = std::max(res, lef + rig);
    }
    return dp[u][q] = res;
}

int main() {
    cin.tie(nullptr);
    cin >> n >> q;
    for(int i= 1; i<= n-1; ++i) {
        int u, v, c;
        cin >> u >> v >> c;pip
    }
    for(int i=1;i<=n;++i)
        for(int j= 0; j<=q; ++j) dp[i][j] = -1;
    cout << solve(1, 0, q);
    return 0;
}
