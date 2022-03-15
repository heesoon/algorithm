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

void buildTreeByDFS(int cIdx, int pIdx, long long costSum){
    vDepths[cIdx] = vDepths[pIdx]+1;
    vCosts[cIdx] = costSum;

    for(auto p : vMap[cIdx]){
        int nIdx = p.first;
        int cost = p.second;

        if(pIdx == nIdx) continue;
        vSparseTable[nIdx][0] = cIdx;
        buildTreeByDFS(nIdx, cIdx, costSum+cost);
    }
}

int getLCA(int u, int v){
    if(vDepths[u] < vDepths[v]) std::swap(u, v);
    for(int i = K_MAX; i >= 0; i--){
        if((vDepths[u]-vDepths[v]) >= (1 << i)){
            u = vSparseTable[u][i];
        }
    }

    if(u == v) return u;

    for(int k = K_MAX; k >= 0; k--){
        if(vSparseTable[u][k] != vSparseTable[v][k]){
            u = vSparseTable[u][k];
            v = vSparseTable[v][k];
        }
    }

    return vSparseTable[u][0];
}

int getK(int u, int v, int k){
    int lca = getLCA(u, v);
    int distUtoLca = vDepths[u] - vDepths[lca];
    int distVtoLca = vDepths[v] - vDepths[lca];

    if(k <= distUtoLca+1){
        int kdiff = k-1;
        for(int i = K_MAX; i >= 0; i--){
            if(kdiff&(1<<i)){
                u = vSparseTable[u][i];
                kdiff = kdiff - (1 << i);
            }
        }
        return u;
    }
    else{
        int kdiff = distVtoLca - (k - distUtoLca) + 1;
        for(int i = K_MAX; i >= 0; i--){
            if(kdiff&(1<<i)){
                v = vSparseTable[v][i];
                kdiff = kdiff - (1 << i);
            }
        }
        return v;
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

    buildTreeByDFS(1, 0, 0);

    // build dists and parents of K
    for(int k = 1; k <= K_MAX; ++k){
        for(int i = 1; i <= N; ++i){
            vSparseTable[i][k] = vSparseTable[vSparseTable[i][k-1]][k-1];
        }
    }

    std::cin >> M;
    while(M--){
        int op;
        std::cin >> op;

        if(op == 1){
            int u, v;
            std::cin >> u >> v;
            int lca = getLCA(u, v);
            std::cout << vCosts[u] + vCosts[v] - 2*vCosts[lca] << "\n";
        }
        else{
            int u, v, k;
            std::cin >> u >> v >> k;
            std::cout << getK(u, v, k) << "\n";
        }
    }

    return 0;
}

// https://jason9319.tistory.com/317