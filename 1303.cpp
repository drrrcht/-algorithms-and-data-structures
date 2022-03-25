#include <string.h>
#include<vector>
#include<list>
#include "iostream"

using namespace std;
int M;
int dp[5100];
int R[5100];
pair<int,int> ans[5100];
void solve() {
    int l,r;
    cin >> M;
    dp[0] = -1;
    while(true) {
        cin >> l >> r;
        if(l == 0 and r == 0) break;
        if(l > M or r < 0) continue;
        if(l<=0) {
            if(r > dp[0]) {
                ans[0] = make_pair(l,r);
                dp[0] = r;
            }
        }else {
            R[l] = max(R[l],r);
        }
    }
    for(int i = 1;i<=M;i++) {
        if(dp[i - 1] > R[i]) {
            ans[i] = ans[i - 1];
            dp[i] = dp[i - 1];
        }else {
            ans[i] = make_pair(i,R[i]);
            dp[i] = R[i];
        }
    }
    if(dp[0] == -1 or dp[0] == 0) {
        cout << "No solution"<<endl;
        return;
    }
    int prev = 0;
    vector<pair<int,int>> seg;
    seg.push_back(ans[0]);
    prev = dp[0];
    while(prev < M) {
        if(dp[prev] == prev) {
            cout <<"No solution"<<endl;
            return;
        }else {
            seg.push_back(ans[prev]);
            prev = dp[prev];
            if(prev >= M) {
                break;
            }
        }
    }
    cout << seg.size() <<endl;
    for(auto e:seg) {
        cout << e.first <<" "<<e.second<<endl;
    }
}
int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    solve();
    return 0;
}
