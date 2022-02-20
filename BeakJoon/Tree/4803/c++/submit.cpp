#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

std::vector<std::vector<int>> G;
std::vector<bool> visited;

bool solve(int idx, int pIdx){

}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int tc = 1;
    while(1){
        int cnt = 0;
        int n, m;
        std::cin >> n >> m;
        if(n == 0 && m == 0) break;

        G = std::vector<std::vector<int>>(n+1);
        visited.assign(n+1, false);

        for(int i = 0; i < m; i++){
            int f, t;
            G[f].push_back(t);
            G[t].push_back(f);
        }

        for(int i = 1; i <= n; i++){
            if(visited[i] == false){
                if(solve(i, 0) == true) cnt++;
            }
        }

        std::cout << "Case " << tc << ": ";
        if(cnt == 0) std::cout << "No trees" << "\n";
        else if(cnt == 1) std::cout << "There is one tree" << "\n";
        else std::cout << "A forest of " << cnt << " trees" << "\n";

        G.clear();
        std::fill(visited.begin(), visited.end(), false);
        tc++;
    }
    return 0;
}