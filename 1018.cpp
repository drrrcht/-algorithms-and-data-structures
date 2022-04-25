#include <bits/stdc++.h>

#define MAX std::max(result, (k == q?0:tree[current][lindex] + solve(lindex, current, q - k - 1))+(k == 0?0:tree[current][rindex] + solve(rindex, current, k - 1)));

int N,Q;
int tree[101][101], DP[101][101];

int solve (int short current, int short parent, int short q){
    if (q <= 0) return 0;
    int flag=-1;
    int lindex = flag;
    int rindex = flag;
    int & result = DP[current][q];
    if (result != -1) return result;
    int i = 0;
    while(i < 101) {
        if (tree[current][i] != -1 and i != parent) {
            lindex = i;
            break;
        }
        i++;
    }
    int j = (lindex == -1?0:lindex+1);
    while(j < 101) {
        if (tree[current][j] != -1 and j != parent) {
            rindex = j;
            break;
        }
        j++;
    }
    if (lindex == -1 or rindex == -1) return 0;
    int k = 0;
    while(k <= q) {
        result = MAX;
        k++;
    }
    return result;
}
int main(){
    std::cin>>N>>Q;
    memset (tree, -1, sizeof tree);
    memset (DP, -1, sizeof DP);
    int i = 0;
    while(i < N){
        int j = 0, x, y, z;
        while(j < N) {
            std::cin>>x>>y>>z;
            tree[x][y] = z;
            tree[y][x] = z;
            j++;
        }
        i++;
    }
    std::cout<<solve (1, 0, Q)<<"\n";
    return 0;
}
