#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int N, M;
std::vector<int> v(9, 0);

void solve(int idx, int visited){
    if(idx == M){
        for(int i = 0; i < M; i++){
            std::cout << v[i] << " ";
        }
        std::cout << "\n";
        return;
    }

    for(int i = 1; i <= N; i++){
        if(visited & (1 << i)) continue;
        v[idx] = i;
        solve(idx+1, visited | (1 << i));
    }
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    std::cin >> N >> M;
    solve(0, 0);
    return 0;
}