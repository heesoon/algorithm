#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <limits>

int N, M, K;
const int INF  = std::numeric_limits<int>::max()/2;
std::vector<std::vector<std::tuple<int,int,int>>> G;
std::vector<std::vector<int>> DP;

void solve(int start){
    // cost, distance, node
    std::priority_queue<std::tuple<int,int,int>, std::vector<std::tuple<int,int,int>>, std::greater<std::tuple<int,int,int>>> PQ;
    PQ.push(std::make_tuple(0, 0, start));
    DP[1][0] = 0;

    while(!PQ.empty()){
        int fTime = std::get<0>(PQ.top());
        int fCost = std::get<1>(PQ.top());
        int fNode = std::get<2>(PQ.top());
        PQ.pop();

        if(DP[fNode][fCost] < fTime) continue;

        for(auto p : G[fNode]){
            int nNode = std::get<0>(p);
            int nCost = std::get<1>(p) + fCost;
            int nTime = std::get<2>(p) + fTime;

            if(nCost > M) continue;
            if(DP[nNode][nCost] <= nTime) continue;

            for(int i = nCost; i <= M; i++){
                if(DP[nNode][i] > nTime){
                    DP[nNode][i] = nTime;
                }
            }

            PQ.push(std::make_tuple(nTime, nCost, nNode));
        }
    }
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while(T--){
        std::cin >> N >> M >> K;
        G = std::vector<std::vector<std::tuple<int,int,int>>>(N+1);
        DP.assign(N+1, std::vector<int>(M+1, INF));

        for(int i = 0; i < K; i++){
            int u, v, c, d;
            std::cin >> u >> v >> c >> d;
            G[u].push_back(std::make_tuple(v, c, d));
        }

        solve(1);

        auto ans = *std::min_element(DP[N].begin(), DP[N].end());
        if(ans == INF) std::cout << "Poor KCM" << "\n";
        else std::cout << ans << "\n";

        G.clear();
        DP.clear();
    }
    return 0;
}

// https://cocoon1787.tistory.com/440