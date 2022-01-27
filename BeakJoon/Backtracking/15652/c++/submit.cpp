#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int N, M;
std::vector<int> v(9, 0);

void solve(int idx, int cnt){
    if(cnt == M){
        for(int i = 0; i < M; i++){
            std::cout << v[i] << " ";
        }
        std::cout << "\n";
        return;
    }

    for(int i = 1; i <= N; i++){
        if(i < idx) continue;
        v[cnt] = i;
        solve(i, cnt+1);
    }
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    std::cin >> N >> M;
    solve(0, 0);
    return 0;
}