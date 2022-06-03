#include<bits/stdc++.h>


#define pii std::pair<int,int>
#define all(a) a.begin(),a.end()
#define cin std::cin
#define cout std::cout
#define data const int N=900;const int M=8100;bool vis[N+5][M+5];pii from[N+5][M+5];char str[N+5][M+5];
#define ppp from[r.first][r.second]=p;str[r.first][r.second]=(d + '0');
#define pip pii r(p.first + d, p.second + d * d);if(vis[r.first][r.second]) continue;vis[r.first][r.second]=1;ppp
#define while1 ans= ans+str[a][b];pii p=from[a][b];a=p.first;b=p.second;

data
void bfs(){
    std::queue<pii>Q;
    Q.push({0,0});
    vis[0][0]=true;

    for(int digit=1; digit<=100; digit++){
        std::queue<pii>tmp;
        while(!Q.empty()){
            pii p=Q.front();
            Q.pop();
            for(int d=1; d<=9; d++){
                pip tmp.push(r);
            }
        }
        swap(tmp,Q);
    }
}

int main(){

    bfs();

    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        if(a>N || b>M || !vis[a][b]) cout << "No solution\n";
        else{
            std::string ans;
            while(a and b){
                while1
            }
            reverse(all(ans));
            cout << ans << '\n';
        }
    }
}
