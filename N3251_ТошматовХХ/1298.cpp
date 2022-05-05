#include <iostream>
#include <string.h>

#define RES p[pt1 + di[i]][pt2 + dj[i]]--;
#define RIS p[pt1 + di[j]][pt2 + dj[j]] == 0
#define RSS  a[k].first = pt1;a[k].second = pt2;b[pt1][pt2] = true;
#define RRS p[i][j]++;c[i][j]++;

using namespace std;

std::pair<int,int> a[100000];
bool b[100][100];
int di[8] = {1, 1, -1, -1, 2, -2, 2, -2};
int dj[8] = {2, -2, 2, -2, 1, 1, -1, -1};
int n;
bool ok;
int p[100][100], c[100][100];

bool check(int x, int y) {
    return ((x >= 1) and (y >= 1) and (x <= n) and (y <= n) and (!b[x][y]));
}

auto solve(int pt1, int pt2, int k) {
    RSS
    int i = 0;
    while(i < 8) {
        if (check(pt1 + di[i], pt2 + dj[i]))
            RES
            i++;
    }

    if ( k == n*n ) {
        ok = 1;
        return;
    }

    bool checked[10];
    int dir = 0;
    memset(checked, 0, sizeof(checked));

    while (1) {
        int t1, t2;
        bool f = 0;
        int mp = 0;
        int j = 0;
        while( j < 8) {
            if (check(pt1 + di[j], pt2 + dj[j])) {
                if (RIS) {
                    f = 0;
                    break;
                }
                if (((mp == 0) or (p[pt1 + di[j]][pt2 + dj[j]] < mp)) and (!checked[j])) {
                    int res = pt1 + di[j];
                    t1 = res;
                    int res1= pt2 + dj[j];
                    int resf = p[pt1 + di[j]][pt2 + dj[j]];
                    t2 = res1;
                    mp = resf;
                    f = 1;
                    dir = j;
                }
            }
            j++;
        }

        if ( !f ) break;
        checked[dir] = 1;
        solve(t1, t2, k + 1);
        if (ok) return;
    }

    b[pt1][pt2] = 0;
}


int main() {
    cin>>n;
    int i = 1;
    while(i <= n) {
        int j = 1;
        while(j <= n) {
            int k = 0;
            while(k < 8) {
                if (check(i + di[k], j + dj[k])) {
                    RRS
                }
                k++;
            }
            j++;
        }
        i++;
    }
    int d = 1;
    while(d <= n) {
        int j1 = 1;
        while(j1 <= n) {
            solve(d, j1, 1);
            if (ok) break;
            int k1 = 1;
            while(k1 <= n) {
                int k2 = 1;
                while( k2 <= n) {
                    p[k1][k2] = c[k1][k2];
                    k2++;
                }
                k1++;
            }
            j1++;
        }
        if (ok) break;
        d++;
    }
    if ( ok ) {
        int i1 = 1;
        while(i1 <= n*n) {
            std::cout << char(a[i1].first + 'a' - 1) << a[i1].second <<"\n";
            i1++;
        }
    }
    else {
        std::cout<<"IMPOSSIBLE\n";
    }
    return 0;
}
