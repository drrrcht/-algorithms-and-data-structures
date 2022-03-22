#include<iostream>
#include<cstdio>
#include <iomanip>
using namespace std;

#define MAX 30005


double *c = new double[MAX];
double *s = new double[MAX];


int main()
{
    int n;

    double a0,an1;
    while(EOF != n && cin>>n)
    {
        cin>>a0>>an1;

        s[0] = 0.0;
        for(int i = 1; i < n+1; i += 1)
        {
            cin>>c[i];
            s[i] = s[i-1]+c[i];
        }

        float a1 = ((1.0*(n*a0))+an1);

        for(int i = 1; i < n+1; i += 1) a1 -= 2*s[i];
        a1 =a1/ (n+1);

        std::cout << std::fixed << std::setprecision(2)<<a1;
    }
}