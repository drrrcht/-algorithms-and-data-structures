#include <iostream>
#include <cstdio>
#define pf printf
using namespace std;
int n, ans;

bool isprime(int v){
    int i = 2;
    while(i*i <= v) {
        if (v%i == 0) {
            return false;
        }
        ++i;
    }
    return true;
}

int main() {
    int T;
    cin>>T;
    while (T --) {
        cin>>n;
        if (isprime(n)) {
            cout<<n<<'\n';
        }
        else if (n%2 == 0){
            ans = n - 3;
            while (!isprime(ans) or !isprime(n - ans)) {
                ans =ans- 2;
            }
            cout<<ans<<' '<<n-ans<<'\n';
            continue;
        }
        else {
            ans = n - 2;
            if (isprime(ans)) {
                pf("%d 2\n",ans);
                continue;
            }
            ans -= 2;
            while (!isprime(ans)) {
                ans = ans- 2;
            }
            printf("%d ",ans);
            n =n- ans;
            if (n == 4) {
                puts("2 2");
                continue;
            }
            ans = n - 3;
            while (!isprime(ans) or !isprime(n - ans)) {
                ans =ans- 2;
            }
            pf("%d %d\n",ans, n - ans);
        }
    }
    return 0;
}
