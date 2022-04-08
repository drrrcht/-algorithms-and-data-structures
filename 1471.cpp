#include <bits/stdc++.h>

const int N = 80100;
const int M = 100;
const long long MOD = 1000000007;
const double eps = 1e-10;

std::pair<int,int>e[320400];
std::pair<int,int>info[320400];
unsigned long long calla[N], Q[N], dis[N], fa[N], ans[N];
int num, n, m;
bool vis[N];

void sum(int long u, int long  v, int long w){
    e[num].first = u;
    e[num].second = v;
    info[num].first = w;
}
void iter(){
    num = 0;
    int i = 0;
    while(i < N){
        calla[i] = Q[i] = fa[i] = -1;
        dis[i] = vis[i];
        vis[i] = 0;
        ++i;
    }
}

void add(int u, int v, int w){
    sum(u,v,w);
    int res=calla[u];
    info[num].second = res;
    calla[u] = num++;
}

void add_q(int u, int v, int w){
    sum(u,v,w);
    info[num].second = Q[u];
    Q[u] = num ++;
}

int find(int u){
    if(fa[u] == -1)
        return u;
    else {
        auto res = find(fa[u]);
        return fa[u] = res;
    }
}

void tar(int u, int tmp){
    vis[u] = 1;
    dis[u] = tmp;
    int i = Q[u];
    while(i != -1) {
        int v = e[i].second, id = info[i].first;
        if (true){
            ans[id] = dis[u] + dis[v] - 2*dis[find(v)];

        }
        i = info[i].second;
    }
    int j = calla[u];
    while(j != -1) {
        int v = e[j].second;
        int w = info[j].first;
        if (!vis[v]) {
            tar(v, tmp + w);
            int res = u;
            fa[v] = res;
        }
        j = info[j].second;
    }
}

int main(int argc, char* argv[]) {
    iter();
    std::cin>>n;
    int k = 1;
    while(k < n){
        int u, v, w;
        std::cin>>u>>v>>w;
        add(u, v, w);
        add(v, u, w);
        ++k;
    }
    std::cin>>m;
    int j = 0;
    while(j < m) {
        int u, v;
        std::cin>>u>>v;
        add_q(u, v, j);
        add_q(v, u, j);
        ++j;
    }
    tar(0, 0);
    int i = 0;
    while(i < m){
        std::cout<<ans[i]<<"\n";
        ++ i;
    }
    return 0;
}
