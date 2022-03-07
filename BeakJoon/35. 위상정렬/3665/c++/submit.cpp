#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <limits>

std::vector<int> vRanks;
std::vector<int> vInDegree;
std::vector<std::vector<int>> vMap;

void solve(){
    std::queue<int> Q;

    for(auto i = 1; i < vInDegree.size(); i++){
        if(vInDegree[i] == 0){
            Q.push(i);
        }
    }

    if(Q.size() == 0){
        // this case is cycle
        std::cout << "IMPOSSIBLE" << "\n";
        return;
    }

    while(Q.empty() == false){

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

        solve();

        vRanks.clear();
        vInDegree.clear();
        vMap.clear();
    }
    return 0;
}

// https://justicehui.github.io/icpc/2019/08/31/BOJ3665/
// https://js1jj2sk3.tistory.com/101