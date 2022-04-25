#include <bits/stdc++.h>

#define INF 1000000007
#define MIN std::min(result,1+rec(sumSquare-i*i,sum-i))

int dp[8101][901];
int rec(int sumSquare,int sum){
    if(sumSquare>8100 or sum>900)
        return INF;

    if(sumSquare<0 or sum<0)
        return INF;

    if(!sumSquare and !sum)
        return 0;

    if(dp[sumSquare][sum]!=-1)
        return dp[sumSquare][sum];

    int result=INF;
    int i=1;
    while(i<=9){
        result=MIN;
        i++;
    }

    return dp[sumSquare][sum]=result;

}

void print(int sumSquare,int sum){
    if(sumSquare<0 or sum<0)
        return ;
    if(!sumSquare and !sum)
        return;
    int i=1;
    while(i<=9) {
        if (rec(sumSquare, sum) == 1 + rec(sumSquare - i * i, sum - i)) {
            std::cout << i;
            print(sumSquare - i * i, sum - i);
            return;
        }
        i++;
    }


}


int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    std::cin>>n;
    while(n--){
        int x,y;
        std::cin>>x>>y;

        int ans=rec(y,x);
        if(ans==INF||ans>100)
            std::cout<<"No solution"<<"\n";
        else
        {
            print(y,x);
            std::cout<<"\n";
        }
    }


    return 0;
}
