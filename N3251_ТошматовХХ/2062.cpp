#include <bits/stdc++.h>
#define RAS int long long sum = 0;while(0 < i) { sum = sum + A[i], i -= i & -i; }return sum;
#define RSE add(j, v);add(k+1, -v);
#define RSS while (i <= n) { A[i] += k, i += i & -i; }
#define REE while(isdigit(ch = getc(stdin))) { ret = ret * 10 + ch - '0'; }
#define EEE while(!isdigit(ch = getc(stdin)));ret = ch - '0';
const int maxn = 300001;
long long A[maxn+2];
int init[maxn];
int n;
std::vector<int> D[maxn+1];

int long long query(int i){RAS}
void add(int i, int long long k){RSS}
void update(int j, int k, long long v){RSE}
inline int getint(){int ret, ch;EEE REE return ret;}

void getDivs(){
    int i = 1;
    while(i <= n) {
        int j = 1;
        while( j * i <= n) {
            D[j * i].push_back(i);
            ++j;
        }
        ++i;
    }
}

int main(){
    n = getint();
    getDivs();
    int i = 1;
    while(i <= n){
        init[i] = getint();
        ++i;
    }
    int q = getint();
    while(q--){
        int opt = getint();
        if(opt == 1){
            int i;
            i = getint();
            long long ans;
            ans = init[i];
            for(auto d : D[i])
                ans =ans+ query(d);
            std::cout<<ans<<'\n';
        }
        else{
            int l = getint(), r = getint(), d = getint();
            update(l, r, d);
        }
    }
}
