#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

int n, m;
const int INF = std::numeric_limits<int>::max()/2;
std::vector<std::vector<long long>> G;

void printAns(){
    for(int y = 1; y <= n; y++){
        for(int x = 1; x <= n; x++){
            if(G[y][x] == INF) std::cout << 0 << " ";
            else std::cout << G[y][x] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void solve(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                    G[i][j] = std::min(G[i][j], G[i][k]+G[k][j]);
            }
        }
    }
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    std::cin >> n;
    std::cin >> m;
    G.assign(n+1, std::vector<long long>(n+1, INF));
    
    for(int i = 0; i <= n; i++){
        G[i][i] = 0;
    }

    for(int i = 0; i < m; i++){
        int from, to, weight;
        std::cin >> from >> to >> weight;
        if(G[from][to] > weight) G[from][to] = weight; // 이 부분이 잘 이해가 안됨
    }

    solve();
    printAns();

    return 0;
}