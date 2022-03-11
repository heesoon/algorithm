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
std::vector<std::vector<std::pair<int,int>>> vMap;
std::vector<std::vector<int>> vSparseTables;
std::vector<std::vector<int>> vMinDists;
std::vector<std::vector<int>> vMaxDists;

std::pair<int,int> solve(int u, int v){
    int retMin = std::numeric_limits<int>::max()/2;
    int retMax = 0;

    if(vDepth[u] != vDepth[v]){
        if(vDepth[u] < vDepth[v]){
            std::swap(u, v);
        }

        auto dist = vDepth[u] - vDepth[v];

        for(int i = 0; i <= H; i++){
            if((dist&0x1) == 1){
                retMin = std::min(retMin, vMinDists[u][i]);
                retMax = std::max(retMax, vMaxDists[u][i]);
                u = vSparseTables[u][i];
            }

            dist >>= 1;
        }
    }

    if(u == v) return std::make_pair(retMin, retMax);

    for(int i = H; i >= 0; i--){
        if(vSparseTables[u][i] != vSparseTables[v][i]){
            retMin = std::min(retMin, std::min(vMinDists[u][i], vMinDists[v][i]));
            retMax = std::max(retMax, std::max(vMaxDists[u][i], vMaxDists[v][i]));
            u = vSparseTables[u][i];
            v = vSparseTables[v][i];
        }
    }

    retMin = std::min(retMin, std::min(vMinDists[u][0], vMinDists[v][0]));
    retMax = std::max(retMax, std::max(vMaxDists[u][0], vMaxDists[v][0]));

    return std::make_pair(retMin, retMax);
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int N;
    std::cin >> N;

    vDepth.assign(N+1, 0); vDepth[0] = -1;
    vVisited.assign(N+1, false); vVisited[0] = true;
    vMap = std::vector<std::vector<std::pair<int,int>>>(N+1);
    vSparseTables.assign(N+1, std::vector<int>(H+1, 0));
    vMinDists.assign(N+1, std::vector<int>(H+1, std::numeric_limits<int>::max()/2));
    vMaxDists.assign(N+1, std::vector<int>(H+1, 0));

    for(int i = 0; i < N-1; i++){
        int a, b, c;
        std::cin >> a >> b >> c;
        vMap[a].push_back(std::make_pair(b, c));
        vMap[b].push_back(std::make_pair(a, c));
    }

    std::queue<int> Q;
    Q.push(1); vVisited[1] = true;

    while(Q.empty() == false){
        auto fVertex = Q.front();
        Q.pop();
        
        for(const auto &p : vMap[fVertex]){
            auto nVertex = p.first;
            auto dist = p.second;

            if(vVisited[nVertex] == false){
                vVisited[nVertex] = true;
                vDepth[nVertex] = vDepth[fVertex]+1;
                vSparseTables[nVertex][0] = fVertex; // 2^0
                vMinDists[nVertex][0] = vMaxDists[nVertex][0] = dist;
                Q.push(nVertex);
            }
        }
    }

    // build sparse table
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= H; j++){
            vSparseTables[i][j] = vSparseTables[vSparseTables[i-1][j-1]][j-1];
            vMaxDists[i][j] = std::max(vMaxDists[i][j-1], vMaxDists[vSparseTables[i][j-1]][j-1]);
            vMinDists[i][j] = std::min(vMinDists[i][j-1], vMinDists[vSparseTables[i][j-1]][j-1]);
            if(vSparseTables[i][j] == 0) break;
        }
    }

    int M;
    std::cin >> M;
    for(int i = 0; i < M; i++){
        int u, v;
        std::cin >> u >> v;
        auto ans = solve(u, v);
        std::cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}