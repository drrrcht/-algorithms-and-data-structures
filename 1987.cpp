#include<bits/stdc++.h>


#define MAX 100005


int n,m;
std::vector<std::pair<std::pair<long long,char >, int > >points;
long long p[MAX];
std::unordered_map<long long,int>ans;
void input(){
    int j=0;
    while(j<n){
        int a,b;
        std::cin>>a>>b;
        points.push_back({{a,'a'},j+1});
        points.push_back({{b,'c'},j+1});
        j++;
    }
}
void solve(){
    sort(points.begin(),points.end());
    std::stack<int >open;
    for(int i=0;i<points.size();i++){
        long long a;
        a = points[i].first.first;
        int ch;
        ch = points[i].first.second;
        int idx;
        idx = points[i].second;
        if(ch=='a')open.push(idx);
        else if(ch=='b'){
            int A = open.top();
            (open.size()==0)?ans[a]=-1: ans[a]=A;
        }
        else {
            open.pop();
        }
    }
    int i=0;
    while(i<m){
        if(ans[p[i]]==0)ans[p[i]]=-1;
        std::cout<<ans[p[i]]<<"\n";
        i++;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin>>n;
    input();
    std::cin>>m;
    for(int i=0;i<m;i++){
        std::cin>>p[i];
        points.push_back({{p[i],'b'},-1});
    }
    solve();
}
