#include <cstdio>
#include <map>
#include <vector>

using namespace std;

#define pb push_back
#define sf scanf

const int maxn = (int)4e5 + 7;


int n, q, a[maxn];
map < int, vector < int > > t;

void solve(){
    for(int i = 1; i <= q; ++i){
        int l, r, x;
        sf("%d %d %d", &l, &r, &x);
        auto it = lower_bound(t[x].begin(), t[x].end(), l);
        if(it != end(t[x]) && *it <= r)
            putchar('1');
        else
            putchar('0');
    }
}
int main(){
    sf("%d", &n);
    for(int i = 1; i <= n; ++i){sf("%d", &a[i]), t[a[i]].pb(i);}
    sf("%d", &q);
    solve();
    return 0;
}
