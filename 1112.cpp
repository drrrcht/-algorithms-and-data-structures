#include "list"
#include "iostream"

using namespace std;
pair<int,int> a[110];

pair<int,int> d[3000];

int n;

int main() {
    scanf("%d", &n);
    for ( int i = 0; i < n; i++ ) {
        scanf("%d%d", &a[i].first, &a[i].second);
        if ( a[i].first > a[i].second ) {
            int c = a[i].first;
            a[i].first = a[i].second;
            a[i].second = c;
        }
    }

    for ( int i = 1; i <= 2050; i++ ) {
        d[i].second = d[i-1].second;
        d[i].first = d[i-1].first;

        for ( int j = 0; j < n; j++ )
            if (a[j].second == i - 1000 ) {
                if ( d[a[j].first + 1000].second + 1 > d[i].second ) {
                    d[i].second = d[a[j].first + 1000].second + 1;
                    d[i].first = j;
                }
            }
    }

    printf("%d\n", d[2000].second);

    pair<int,int> ans[110];
    int nans = 0;

    int i = 2000;
    while ( d[i].second > 0 ) {
        ans[nans] = a[d[i].first];
        nans++;
        i = a[d[i].first].first + 1000;
    }

    for ( int i = nans-1; i >= 0; i-- )
        printf("%d %d\n", ans[i].first, ans[i].second);

    return 0;
}
