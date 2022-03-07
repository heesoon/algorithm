#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <limits>

std::vector<int> vIndegree;
std::vector<std::vector<int>> vMap;

void solve(){
    std::queue<int> qGraph;

    for(auto i = 1; i < vIndegree.size(); i++){
        if(vIndegree[i] == 0){
            qGraph.push(i);
        }
    }

    while(qGraph.empty() == false){
        auto fIdx = qGraph.front();
        qGraph.pop();

        std::cout << fIdx << " ";

        for(const auto &nIdx : vMap[fIdx]){
            vIndegree[nIdx]--;
            if(vIndegree[nIdx] == 0){
                qGraph.push(nIdx);
            }
        }
    }

    std::cout << "\n";
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int N, M;
    std::cin >> N >> M;

    vIndegree.assign(N+1, 0);
    vMap = std::vector<std::vector<int>>(N+1);

    for(int i = 0; i < M; i++){
        int a, b;
        std::cin >> a >> b;
        vIndegree[b]++;
        vMap[a].push_back(b);
    }

    solve();
    return 0;
}