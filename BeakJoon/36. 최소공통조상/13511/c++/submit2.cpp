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

int getLCA(int u, int v){
    if(u == v) return u;

    if(vDepths[u] < vDepths[v]) std::swap(u, v);

    int diff = vDepths[u] - vDepths[v];
    for(int i = K_MAX; i >= 0; i--){
        if(diff&(1 << i)){
            u = vSparseTable[u][i];
            diff = diff - (1 << i);
        }
    }

    if(u != v){
        for(int k = K_MAX; k >= 0; k--){
            if(vSparseTable[u][k] != vSparseTable[v][k]){
                u = vSparseTable[u][k];
                v = vSparseTable[v][k];
            }
        }
    }

    return vSparseTable[u][0];
}

int getK(int u, int v, int k){
    int lca = getLCA(u, v);
    int distUtoLca = vDepths[u] - vDepths[lca];
    int distVtoLca = vDepths[v] - vDepths[lca];

    if(k <= distUtoLca){
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
        int kdiff = distVtoLca - (k - distUtoLca);
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

    vDepths[1] = 1;

    //buildTreeByDFS(1);
    buildTreeByBFS(1);

    // build dists and parents of K
    for(int k = 0; k <= K_MAX; k++){
        for(int i = 2; i <= N; i++){
            int father = vSparseTable[i][k];
            if(father){
                vSparseTable[i][k+1] = vSparseTable[father][k];
            }
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

// https://www.acmicpc.net/board/view/56255

정답
5 //
5
3
3
7
7
1 //
3
4
2 //
1
3
4
4 //
3
1
4 //
3
1
2

4
1 2 5
1 3 3
4 3 4
20
1 1 2
1 2 1
1 1 3
1 3 1
1 4 1
1 1 4
2 1 4 1
2 1 4 2
2 1 4 3
2 2 4 1
2 2 4 2
2 2 4 3
2 2 4 4
2 4 1 1
2 4 1 2
2 4 1 3
2 4 2 1
2 4 2 2
2 4 2 3
2 4 2 4