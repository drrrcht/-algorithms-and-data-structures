#include <bits/stdc++.h>
#define MAXN 1005
#define SET std::set<int>::iterator setIterator;
#define PIS pPocessed[index] = 1;isSuspect[index] = 0;
#define CIS cProcessed[index] = 1;isSuspect[index] = 0;
#define PIF if (pPocessed[index]) { return; }
#define CIF if (cProcessed[index]) { return; }
#define sf scanf
#define PC parents[child-1].insert(arg-1);children[arg-1].insert(child-1);
#define SR scanfResult = sf("%d", &arg);
int n, child, scanfResult, loop, arg;
std::set<int> victims;
std::map< int, std::set<int> > parents;
std::map< int, std::set<int> > children;
bool isSuspect[MAXN];
bool pPocessed[MAXN];
bool cProcessed[MAXN];
char argc=' ';
bool firstSuspectFound;



void eraseAncestors (int index) {
    SET PIF PIS
    setIterator=parents[index].begin();
    while(setIterator!=parents[index].end() ) {
        eraseAncestors(*setIterator);
        setIterator++;
    }
}

void eraseDescendants (int index) {
    SET CIF CIS
    setIterator=children[index].begin();
    while(setIterator!=children[index].end()) {
        eraseDescendants(*setIterator);
        setIterator++;
    }
}

int main () {
    SET
    std::cin>>n;
    scanfResult = sf("%d", &arg);
    while (scanfResult == 1) {child = arg; SR PC SR}
    std::cin>>argc;
    std::cin>>argc;
    std::cin>>argc;
    std::cin>>argc;
    std::cin>>argc;

    scanfResult = scanf("%d", &arg);
    while (scanfResult == 1) {
        victims.insert(arg-1);
        scanfResult = scanf("%d", &arg);
    }
    loop=0;
    while(loop<n) {
        isSuspect[loop] = true;
        pPocessed[loop] = false;
        cProcessed[loop] = false;
        loop++;
    }
    setIterator=victims.begin();
    while(setIterator!=victims.end()) {
        eraseAncestors(*setIterator);
        eraseDescendants(*setIterator);
        setIterator++;
    }
    firstSuspectFound = false;
    loop=0;
    while(loop<n) {
        if (isSuspect[loop]) {
            if (firstSuspectFound) {
                //printf(" %d", loop + 1);
                std::cout<<' '<<loop+1;
            }

            else{
                //printf("%d", loop + 1);
                std::cout<<loop+1;
            }
            firstSuspectFound = true;
        }
        loop++;
    }
    if (!firstSuspectFound) {
        std::cout<<0;
    }
    std::cout<<'\n';
    return 0;
}
