#include <cstdio>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

const int maxn = (int)4e5 + 7;
int n, q, arr[maxn];


map < int, vector < int > > v;

void solve(){
    for(int i = 1; i <= q; ++i){
        int l, r, x;
        cin>>l>>r>>x;
        auto iterator = lower_bound(v[x].begin(), v[x].end(), l);
        if(iterator != end(v[x]) and *iterator <= r){putc('1',stdout);}
        else{putchar('0');}
    }
}
int main(){
    cin>>n;
    int i=1;
    while (i<=n){
        scanf("%d", &arr[i]), v[arr[i]].push_back(i);
        ++i;
    }
    cin>>q;
    solve();
    return 0;
}
