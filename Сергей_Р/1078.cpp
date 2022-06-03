#include <algorithm>
#include <cstdio>

#define int_all int dp, i, l, p, r;
#define bool1 bool fits_in(segment& s){return l > s.l && r < s.r;}
#define bool2 bool operator<(const segment& s) const {return l < s.l || (l == s.l && r > s.r);}
#define all int_all bool1 bool2
#define pri s[m].dp = 1;s[m].i = m+1;s[m].p = -1;
#define sort sort(s, s + n);
#define pf printf
#define if_zamin if (s[i].fits_in(s[j]) and s[i].dp < s[j].dp + 1)


using namespace std;
struct segment {
    all
}s[512];
int main(void){
    for(int n; scanf("%d", &n) == 1; ){
        int idx, maxl = 0;
        int m = 0;
        while(m < n){
            pri
            scanf("%d %d", &s[m].l, &s[m].r);
            ++m;
        }sort
        int i = 0;
        while (i < n){
            int j = 0;
            while (j < i) {
                if_zamin{
                    s[i].dp = s[j].dp + 1;
                    int res = j;
                    s[i].p = res;
                }
                ++j;
            }
            if(s[i].dp > maxl){
                maxl = s[i].dp;
                idx = i;
            }
            ++i;
        }
        pf("%d\n", s[idx].dp);
        while( idx != -1 ) {
            pf("%d%c", s[idx].i, s[idx].p == -1 ? 10 : 32);
            idx = s[idx].p;
        }
    }
    return 0;
}
