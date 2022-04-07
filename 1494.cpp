#include <bits/stdc++.h>
#define MAX 100100

int x, last, n, a[MAX], k;

int main() {
    std::cin>>n;
    int i = 1;
    while(i <= n){
        std::cin>>x;
        if ( x > last ) {
            int j = last+1;
            while (j <= x-1){
                ++k;
                a[k] = j;
                ++j;
            }
            last = x;
        } 
        else {
            if ( x != a[k] ) {
                std::cout<<"Cheater\n";
                return 0;
            }
            --k;
        }
        ++i;
    }
    std::cout<<"Not a proof\n";
    return 0;
}
