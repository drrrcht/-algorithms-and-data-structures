#include <iostream>
#define MAX 10
void solve(int n){
    bool flag = false;
    int *arr = new int[MAX];
    delete [] arr;
    if (n>=1 and n<=9){std::cout<<n; return;}
    for (int i = 0; i < 10; ++i)
            arr[i] = flag;
    for(int i = 9; i > 1; --i){
        while(!(n % i)){
            n/=i;
            arr[i]=arr[i]+1;
        }
    }
    if(n == 1){
        for(int i = 2; i <= 9; ++i){
            while(arr[i]) {
                arr[i]--;
                std::cout<<i;

            }
        }
    }
    else
        std::cout << -1;
    return;
}


int main()
{
    int num;
    std::cin>>num;
    if(num==0){std::cout<<10; return 0;}
    if(num == 1){std::cout<<1; return 0;}
    solve(num);
    return 0;
}