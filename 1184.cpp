#include <iostream>
#include <iomanip>
#define sf scanf
int N, K, a, b, min = 1, max = 1e7, mid, count, result = 0;

void solve(){
    int *arr = new int[N];
    for (int i = 0; i < N; ++i) {
        sf("%d%*c%d", &a, &b);
        arr[i] = 100 * a + b;
    }
    while (min <= max) {
        mid = (min + max) / 2;
        count = 0;
        for (int i = 0; i < N; i++) count += (arr[i] / mid);
        if (count < K) max = mid - 1;
        else {
            min = mid + 1;
            result = mid;
        }
    }
    delete[] arr;
}

int main() {
    std::cin>>N>>K;
    solve();
    std::cout << result / 100 << "." << std::setw(2) << std::setfill('0') << result % 100;
}

}
