#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <limits>

int V, E;
const int INF = std::numeric_limits<int>::max()/2;
std::vector<std::vector<int>> G;

void solve(){
    for(int k = 1; k <= V; k++){
        for(int i = 1; i <= V; i++){
            for(int j = 1; j <= V; j++){
                    G[i][j] = std::min(G[i][j], G[i][k]+G[k][j]);
            }
        }
    }
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    std::cin >> V >> E;

    G.assign(V+1, std::vector<int>(V+1, INF));
    for(int i = 0; i < E; i++){
        int a, b, c;
        std::cin >> a >> b >> c;
        G[a][b] = c;
    }

    solve();

    int ans = INF;
    for(int i = 1; i <= V; i++){
        if(ans > G[i][i]){
            ans = G[i][i];
        }
    }

    if(ans == INF) std::cout << "-1" << "\n";
    else std::cout << ans << "\n";

    return 0;
}