#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <cmath>

int N, M;
const int NMAX = 1e5;
const int KMAX  = std::ceil(std::log2(100'000));

std::vector<int> vDepth(NMAX+1, 0);
std::vector<std::vector<std::pair<int,int>>> vDist;
std::vector<std::vector<std::pair<int,int>>> vMap;
std::vector<std::vector<int>> vSparseTable(NMAX+1, std::vector<int>(KMAX+1, 0));

void buildTreeByBFS(int start){
    std::queue<int> Q;
    Q.push(start);
    vDepth[start] = 1;

    while(!Q.empty()){
        auto cIdx = Q.front();
        Q.pop();

        for(const auto &p : vMap[cIdx]){
            auto nIdx = p.first;
            auto dist = p.second;

            if(vDepth[nIdx] != 0) continue;
            vDepth[nIdx] = vDepth[cIdx]+1;
            vSparseTable[nIdx][0] = cIdx;
            vDist[nIdx][0].first = vDist[nIdx][0].second = dist;
            Q.push(nIdx);
        }
    }
}

void buildTreeByDFS(int cIdx){
    for(auto p : vMap[cIdx]){
        int nIdx = p.first;
        int dist = p.second;

        if(vDepth[nIdx] != 0) continue;

        vDepth[nIdx] = vDepth[cIdx]+1;
        vSparseTable[nIdx][0] = cIdx;
        vDist[nIdx][0].first = vDist[nIdx][0].second = dist;
        buildTreeByDFS(nIdx);
    }
}

std::pair<int,int> solve(int a, int b){
    int minValue = std::numeric_limits<int>::max()/2;
    int maxVaule = 0;
    int kIdx = 0;

    if(vDepth[a] < vDepth[b]){
        std::swap(a, b);
    }

    int diff = vDepth[a] - vDepth[b];

    while(diff){
        if((diff&0x01) == 1){
            minValue = std::min(minValue, vDist[a][kIdx].first);
            maxVaule = std::max(maxVaule, vDist[a][kIdx].second);
            a = vSparseTable[a][kIdx];
        }

        diff >>= 1;
        kIdx++;
    }

    if(a != b){
        for(int k = KMAX; k >= 0; k--){
            if(vSparseTable[a][k] != vSparseTable[b][k]){
                minValue = std::min(minValue, std::min(vDist[a][k].first, vDist[b][k].first));
                maxVaule = std::max(maxVaule, std::max(vDist[a][k].second, vDist[b][k].second));
                a = vSparseTable[a][k];
                b = vSparseTable[b][k];
            }
        }

        minValue = std::min(minValue, std::min(vDist[a][0].first, vDist[b][0].first));
        maxVaule = std::max(maxVaule, std::max(vDist[a][0].second, vDist[b][0].second));          
    }

    return std::make_pair(minValue, maxVaule);
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    std::cin >> N;

    vMap = std::vector<std::vector<std::pair<int,int>>>(N+1);
    vDist.assign(NMAX+1, std::vector<std::pair<int,int>>(KMAX+1, std::make_pair(0, 0)));
    for(int i = 0; i < N-1; i++){
        int a, b, c;
        std::cin >> a >> b >> c;
        vMap[a].push_back(std::make_pair(b, c));
        vMap[b].push_back(std::make_pair(a, c));
    }

    vDepth[1] = 1;

    //buildTreeByDFS(1);
    buildTreeByBFS(1);

    // build dists and parents of K
    for(int k = 0; k <= KMAX; ++k){
        for(int i = 2; i <= N; ++i){
            int father = vSparseTable[i][k];
            if(father){
                vSparseTable[i][k+1] = vSparseTable[father][k];
                vDist[i][k+1].first = std::min(vDist[i][k].first, vDist[father][k].first);
                vDist[i][k+1].second = std::max(vDist[i][k].second, vDist[father][k].second);
            }
        }
    }

    std::cin >> M;

    for(int i = 0; i < M; i++){
        int a, b;
        std::cin >> a >> b;
        auto ans = solve(a, b);
        std::cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}