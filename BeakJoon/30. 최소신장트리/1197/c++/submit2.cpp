#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
#include <utility>
#include <limits>

std::vector<bool> vVisted;
std::vector<std::vector<std::tuple<int,int>>> G;

int solve(int s){
    int ans = 0;
    std::priority_queue<std::tuple<int,int>> PQ;
    PQ.push(std::make_tuple(0, s));

    while(!PQ.empty()){
        auto fWeight = std::get<0>(PQ.top());
        auto fNode = std::get<1>(PQ.top());
        PQ.pop();
        vVisted[fNode] = true;
        ans += fWeight;

        for(auto p : G[fNode]){
            auto nWeight = std::get<0>(p);
            auto nNode = std::get<1>(p);

            if(vVisted[nNode] == false){
                PQ.push(std::make_tuple(nWeight, nNode));
            }
        }
    }

    return ans;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int V, E;
    std::cin >> V >> E;

    vVisted.assign(V+1, false);
    G = std::vector<std::vector<std::tuple<int,int>>>(V+1);

    for(int i = 0; i < E; i++){
        int a, b, c;
        std::cin >> a >> b >> c;
        G[a].push_back(std::make_tuple(c, b));
        G[b].push_back(std::make_tuple(c, a));
    }

    std::cout << solve(1) << "\n";

    return 0;
}