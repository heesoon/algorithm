#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <limits>

std::vector<int> vRanks;
std::vector<int> vInDegree;
std::vector<std::vector<int>> vMap;

void solve(int n){
    bool bVague = false;
    std::queue<int> Q;
    std::vector<int> ans;

    for(auto i = 1; i < vInDegree.size(); i++){
        if(vInDegree[i] == 0){
            Q.push(i);
        }
    }

    while(Q.empty() == false){
        if(Q.size() > 1){
            bVague = true;
        }

        auto fNode = Q.front();
        ans.push_back(fNode);
        Q.pop();

        for(auto nNode = 1; nNode <= n; nNode++){
            if(vMap[fNode][nNode] == 0) continue;
            vInDegree[nNode]--;
            if(vInDegree[nNode] == 0){
                Q.push(nNode);
            }
        }
    }

    if(bVague == true){
        std::cout << "?\n";
    }
    else if(ans.size() != n){
        std::cout << "IMPOSSIBLE\n";
    }
    else{
        for(const auto &x : ans){
            std::cout << x << " ";
        }
        std::cout << "\n";
    }
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;

    while(T--){
        int n, m;
        std::cin >> n;
        vRanks.assign(n+1, 0);
        vInDegree.assign(n+1, 0);
        vMap.assign(n+1, std::vector<int>(n+1, 0));

        for(int i = 1; i <= n; i++){
            std::cin >> vRanks[i];
        }

        for(int i = 1; i < n; i++){
            for(int j = i+1; j <= n; j++){
                auto a = vRanks[i];
                auto b = vRanks[j];
                vMap[a][b] = 1;
                vInDegree[b]++;
            }
        }

        std::cin >> m;
        for(int i = 0; i < m; i++){
            int a, b;
            std::cin >> a >> b;
            if(vMap[a][b] == 1){
                vMap[a][b] = 0;
                vMap[b][a] = 1;
                vInDegree[b]--;
                vInDegree[a]++;
            }
            else{
                vMap[a][b] = 1;
                vMap[b][a] = 0;
                vInDegree[a]--;
                vInDegree[b]++;                
            }
        }

        solve(n);

        vRanks.clear();
        vInDegree.clear();
        vMap.clear();
    }
    return 0;
}

// https://justicehui.github.io/icpc/2019/08/31/BOJ3665/
// https://glanceyes.tistory.com/6