#include <algorithm>
#include <cstdio>
#include <iostream>

#define sf scanf
#define pf printf

//using namespace std;
struct segment {
    int dp, i;
    int l, p;
    int r;
    bool fits_in(segment& s){
        return l > s.l and r < s.r;
    }
    bool operator<(const segment& s) const {
        return l < s.l or (l == s.l && r > s.r);
    }
}s[512];



int main(){
    int n;
    while( sf("%d", &n) == 1){
        int idx;
        int maxl = 0;
        int i = 0;
        while(i < n){
            int flagp=1;
            int flagm=-1;
            int ip1=i+1;
            s[i].dp = flagp;
            s[i].i = ip1;
            s[i].p = flagm;
            //sf("%d %d", &s[i].l, &s[i].r);
            std::cin>>s[i].l>>s[i].r;
            ++i;
        }
        std::sort(s, s + n);
        int k = 0;
        while(k < n){
            int j = 0;
            while(j < i) {
                if (s[k].fits_in(s[j]) and s[k].dp < s[j].dp + 1) {
                    int res=s[j].dp + 1;
                    s[k].dp = res;
                    s[k].p = j;
                }
                ++j;
            }
            if(s[k].dp > maxl){
                int res=s[k].dp;
                maxl = res;
                idx = k;
            }
            ++k;
        }
        //printf("%d\n", s[idx].dp);
        std::cout<<s[idx].dp<<"\n";
        while( idx != -1){
            std::cout<<s[idx].i;
            pf("%c", s[idx].p == -1 ? 10 : 32);
            idx = s[idx].p;
        }
    }
    return 0;
}
