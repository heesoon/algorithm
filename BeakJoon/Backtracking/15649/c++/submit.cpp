#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int N, M;

void solve(int visited, int m, std::vector<int> v){
    if(m == M){
        for(int i = 0; i < m; i++){
            std::cout << v[i] << " ";
        }
        std::cout << "\n";
        return;
    }

    for(int i = 1; i <= N; i++){
        if(visited & (1 << i)) continue;
        v.push_back(i);
        solve(visited|(1 << i), m+1, v);
        v.pop_back();
    }
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    std::cin >> N >> M;
    int visited = 0;
    std::vector<int> v;
    solve(visited, 0, v);
    return 0;
}