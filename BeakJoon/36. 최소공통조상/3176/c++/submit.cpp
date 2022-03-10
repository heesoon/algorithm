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
        if(vDepth[u] > vDepth[v])
            std::swap(u, v);
        
        for(int i = H; i >= 0; i--){
            if(vDepth[u] <= vDepth[vSparseTables[v][i]]){
                v = vSparseTables[v][i];
                retMin = std::min(retMin, vMinDists[v][i]);
                retMax = std::min(retMax, vMaxDists[v][i]);
            }
        }
    }

    int lcu = u, lcv = v;

    if(u != v){
        for(int i = H; i >= 0; i--){
            if(vSparseTables[u][i] != vSparseTables[v][i]){
                u = vSparseTables[u][i];
                v = vSparseTables[v][i];

                retMin = std::min(retMin, vMinDists[u][i]);
                retMin = std::min(retMin, vMinDists[v][i]);
                retMax = std::min(retMax, vMaxDists[u][i]);
                retMax = std::min(retMax, vMaxDists[v][i]);                
            }
            lcu = vSparseTables[u][i];
            lcv = vSparseTables[v][i];
        }
    }

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

    // build sparse table
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
                vMinDists[nVertex][0] = vMinDists[nVertex][0] = dist;

                for(int i = 1; i <= H; i++){
                    auto prevParentIdx = vSparseTables[nVertex][i-1];
                    vSparseTables[nVertex][i] = vSparseTables[prevParentIdx][i-1];
                    vMinDists[nVertex][i] = std::min(vMinDists[nVertex][i-1], vMinDists[prevParentIdx][i-1]);
                    vMaxDists[nVertex][i] = std::min(vMaxDists[nVertex][i-1], vMaxDists[prevParentIdx][i-1]);
                    if(vSparseTables[nVertex][i] == 0){
                        break;
                    }
                }

                Q.push(nVertex);
            }
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

// https://everenew.tistory.com/96