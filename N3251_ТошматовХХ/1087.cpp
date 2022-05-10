#include <bits/stdc++.h>

//using namespace std;

int main(){
    int n, m;
    std::cin >> n >> m;
    std::vector <int> k(m);
    int d = 0;
    while(d < m) {
        std::cin >> k[d];
        d++;
    }
    std::vector <bool> w(n + 1, false);
    int flag1=1;
    int flag0=0;
    w[0] = flag1;
    w[1] = flag0;
    sort(k.begin(), k.end());
    int i = 2;
    while(i <= n) {
        w[i] = 0;
        int j = 0;
        while(j < m){
            if (i - k[j] >= 0 and w[i - k[j]] == 0){
                w[i] = 1;
                break;
            }
            j++;
        }
        i++;
    }
    (w[n])?std::cout << '1':std::cout << '2';
    return 0;
}
