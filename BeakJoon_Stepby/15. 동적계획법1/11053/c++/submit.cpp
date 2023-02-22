#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> A;
std::vector<int> cache;

int solve(int start){
    int &ret = cache[start+1];
    if(ret != -1){
        return ret;
    }

    ret = 1;
    for(int next = start+1; next < A.size(); next++){
        if(start == -1 || A[start] < A[next]){
            ret = std::max(ret, solve(next)+1);
        }
    }

    return ret;
}

int main(){
    int N;
    int v;
    std::cin >> N;

    for(int i = 0; i < N; i++){
        std::cin >> v;
        A.emplace_back(v);
    }

    cache.assign(1001, -1);
    std::cout << solve(-1) -1 << std::endl;
}