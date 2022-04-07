#include <bits/stdc++.h>
struct info
{
    int first;
    int second;
}temp;

std::vector<info>que;
template<typename T>
void pop_front(std::vector<T> &v) {
    if (v.size() > 0) {
        v.erase(v.begin());
    }
}


int main(){
    int k;
    std::cin>>k;
    for(int i = 1;; i ++){
        std::cin>>temp.first;
        temp.second = i;

        if(temp.first == -1)break;

        if(!que.size()==0 && que.front().second + k == i){
            pop_front(que);
        }
        while(true){
            if(que.size()==0){
                break;
            }

            if(temp.first >= que.back().first){
                que.pop_back();
            }
            else{
                break;
            }
        }

        que.push_back(temp);

        if(i >= k){
            std::cout<<"\n"<<que.front().first;
        }

        }
}
