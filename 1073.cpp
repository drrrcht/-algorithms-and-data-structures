#include <bits/stdc++.h>

const int max = 1000000;
int data[60010]={0,1};
void solve(int n){
    data[1] = 1;
    data[2] = 2;
    int i = 3;
    while(i <= n){
        int min = data[i - 1] + 1;
        int j = 2;
        while(j <= max){
            if (i >= j * j){if (min > data[i - j * j] + 1) min = data[i - j * j] + 1;}
            else break;
            ++j;
        }
        data[i] = min;
        ++i;
    }
}
int main(){
    int n;
    std::cin>>n;
    solve(n);
    std::cout<<data[n];
    return 0;
}
