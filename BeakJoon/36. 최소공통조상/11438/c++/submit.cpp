#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <limits>
#include <cmath>

const int H = std::ceil(std::log2(100'000));

std::vector<bool> vVisited;
std::vector<int> vDepth;
std::vector<std::vector<int>> vMap;
std::vector<std::vector<int>> vSparseTables;

int solve(int u, int v){
    if(vDepth[u] > vDepth[v]){
        std::swap(u, v);
    }

    while(vDepth[u] != vDepth[v]){
        auto dist = vDepth[v] - vDepth[u];

        for(int i = 0; i < H; i++){
            if(dist <= (2 << i)){
                v = vSparseTables[i][v];
                break;
            }
        }
    }

    while(u != v){
        for(int i = 0; i < H; i++){
            if(vSparseTables[i+1][u] == vSparseTables[i+1][v]){
                u = vSparseTables[i][u];
                v = vSparseTables[i][v];
                break;
            }
        }
    }
    return u;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int N;
    std::cin >> N;

    vMap = std::vector<std::vector<int>>(N+1);
    vSparseTables.assign(H+1, std::vector<int>(N+1, 0));
    vVisited.assign(N+1, false);
    vDepth.assign(N+1, 0);

    for(int i = 0; i < N-1; i++){
        int a, b;
        std::cin >> a >> b;
        vMap[a].push_back(b);
        vMap[b].push_back(a);
    }

    // build sparse table
    std::queue<int> Q;
    Q.push(1); vVisited[1] = true;

    while(Q.empty() == false){
        auto fVertex = Q.front();
        Q.pop();
        
        for(const auto &nVertex : vMap[fVertex]){
            if(vVisited[nVertex] == false){
                vVisited[nVertex] = true;
                vDepth[nVertex] = vDepth[fVertex]+1;
                vSparseTables[0][nVertex] = fVertex;
#if 0
                for(int i = 0; i < H; i++){
                    vSparseTables[i+1][nVertex] = vSparseTables[i][vSparseTables[i][nVertex]];
                    if(vSparseTables[i+1][nVertex] == 0) break;
                }
#endif            
                Q.push(nVertex);
            }
        }
    }

    int M;
    std::cin >> M;
    for(int i = 0; i < M; i++){
        int u, v;
        std::cin >> u >> v;
        std::cout << solve(u, v) << "\n";
    }
    return 0;
}