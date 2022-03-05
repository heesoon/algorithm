#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

std::vector<std::vector<int>> G;
std::vector<bool> visited;

bool solve(int idx, int pIdx){
    visited[idx] = true;
    for(auto nIdx : G[idx]){
        if(nIdx == pIdx) continue;
        if(visited[nIdx] == true) return false;
        if(solve(nIdx, idx) == false) return false;
    }
    return true;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int tc = 0;
    while(1){
        int cnt = 0;
        int n, m;
        std::cin >> n >> m;
        if(n == 0 && m == 0) break;

        G = std::vector<std::vector<int>>(n+1);
        visited.assign(n+1, false);

        for(int i = 0; i < m; i++){
            int f, t;
            std::cin >> f >> t;
            G[f].push_back(t);
            G[t].push_back(f);
        }

        for(int i = 1; i <= n; i++){
            if(visited[i] == false){
                if(solve(i, 0) == true) cnt++;
            }
        }

        std::cout << "Case " << ++tc;
        if (cnt == 0) std::cout << ": No trees.";
        else if (cnt == 1) std::cout << ": There is one tree.";
        else std::cout << ": A forest of " << cnt << " trees.";
        std::cout << '\n';

        G.clear();
        visited.clear();
    }
    return 0;
}

// https://mapocodingpark.blogspot.com/2020/05/4803.html