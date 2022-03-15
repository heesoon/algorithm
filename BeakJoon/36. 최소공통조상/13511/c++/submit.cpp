#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <cmath>

int N, M;
const int K_MAX  = std::ceil(std::log2(100'000));

std::vector<int> vDepths;
std::vector<long long> vCosts;
std::vector<std::vector<std::pair<int,int>>> vMap;
std::vector<std::vector<int>> vSparseTable;

void buildTreeByBFS(int start){
    std::queue<int> Q;
    Q.push(start);
    vDepths[start] = 1;

    while(!Q.empty()){
        auto cIdx = Q.front();
        Q.pop();

        for(const auto &p : vMap[cIdx]){
            auto nIdx = p.first;
            auto dist = p.second;

            if(vDepths[nIdx] != 0) continue;

            vDepths[nIdx] = vDepths[cIdx]+1;
            vCosts[nIdx] += (vCosts[cIdx] + dist);
            vSparseTable[nIdx][0] = cIdx;
            Q.push(nIdx);
        }
    }
}

void buildTreeByDFS(int cIdx){
    for(auto p : vMap[cIdx]){
        int nIdx = p.first;
        int dist = p.second;

        if(vDepths[nIdx] != 0) continue;

        vDepths[nIdx] = vDepths[cIdx]+1;
        vCosts[nIdx] += (vCosts[cIdx] + dist);
        vSparseTable[nIdx][0] = cIdx;
        buildTreeByDFS(nIdx);
    }
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    std::cin >> N;

    vDepths.assign(N+1, 0);
    vCosts.assign(N+1, 0);
    vSparseTable.assign(N+1, std::vector<int>(K_MAX+1, 0));
    vMap = std::vector<std::vector<std::pair<int,int>>>(N+1);

    for(int i = 0; i < N-1; i++){
        int u, v, w;
        std::cin >> u >> v >> w;
        vMap[u].push_back(std::make_pair(v, w));
        vMap[v].push_back(std::make_pair(u, w));
    }

    vDepths[1] = 1;

    //buildTreeByDFS(1);
    buildTreeByBFS(1);

    // build dists and parents of K
    for(int k = 0; k <= K_MAX; ++k){
        for(int i = 2; i <= N; ++i){
            int father = vSparseTable[i][k];
            if(father){
                vSparseTable[i][k+1] = vSparseTable[father][k];
            }
        }
    }

    std::cin >> M;
    while(M--){
        int c, u, v, k;
        std::cin >> c >> u >> v;

        if(c == 1){
            int idx = 0;
            long long tmpCost = vCosts[u] + vCosts[v];
            if(vDepths[u] < vDepths[v]) std::swap(u, v);
            int diff = vDepths[u] - vDepths[v];
            while(diff){
                if((diff&0x01) == 1){
                    u = vSparseTable[u][idx];
                }

                diff >>= 1;
                idx++;
            }

            if(u != v){
                for(int d = K_MAX; d >= 0; d--){
                    if(vSparseTable[u][d] != vSparseTable[v][d]){
                        u = vSparseTable[u][d];
                        v = vSparseTable[v][d];
                    }
                }

                u = vSparseTable[u][0];
            }

            tmpCost -= vCosts[u]*2;
            std::cout << tmpCost << "\n";
        }
        else{
            int idx = 0;
            std::cin >> k;
            int ou = u;
            int ov = v;

            if(vDepths[u] < vDepths[v]) std::swap(u, v);
            int diff = vDepths[u] - vDepths[v];
            while(diff){
                if((diff&0x01) == 1){
                    u = vSparseTable[u][idx];
                }

                diff >>= 1;
                idx++;
            }

            if(u != v){
                for(int d = K_MAX; d >= 0; d--){
                    if(vSparseTable[u][d] != vSparseTable[v][d]){
                        u = vSparseTable[u][d];
                        v = vSparseTable[v][d];
                    }
                }

                u = vSparseTable[u][0];
            }

            int dist = vDepths[ou] - vDepths[u] + 1;
            if(k == dist){
                std::cout << u << "\n";
            }
            else if(k < dist){
                for(int i = K_MAX; i >= 0; i--){
                    if(k & (1 << i)){
                        ou = vSparseTable[ou][i];
                        k = k - (1 << i);
                    }
                }

                std::cout << ou << "\n";
            }
            else{
                k -= dist;
                k = vDepths[v] - vDepths[u] + 1 - k;
                for(int i = K_MAX; i >= 0; i--){
                    if(k & (1 << i)){
                        ov = vSparseTable[ov][i];
                        k = k - (1 << i);
                    }
                }

                std::cout << ov << "\n";
            }
        }
    }

    return 0;
}