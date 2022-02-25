#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <limits>

int n, m;
std::vector<std::vector<std::pair<int,int>>> G;
const int INF = std::numeric_limits<int>::max()/2;

std::vector<long long> solve(int start){
    bool bcycle = false;
    std::vector<long long> distance(n+1, INF);
    distance[start] = 0;

    for(int iter = 0; iter < n; iter++){
        for(int i = 1; i <= n; i++){
            for(auto p : G[i]){
                int nIdx = p.first;
                int weight = p.second;

                if(distance[i] != INF && distance[nIdx] > distance[i] + weight){
                    distance[nIdx] = distance[i] + weight;
                    if(iter == n-1){
                        bcycle = true;
                    }
                }
            }
        }
    }

    if(bcycle == true) distance.clear();
    return distance;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    std::cin >> n >> m;

    G = std::vector<std::vector<std::pair<int,int>>>(n+1);
    for(int i = 0; i < m; i++){
        int a, b, c;
        std::cin >> a >> b >> c;
        G[a].push_back(std::make_pair(b, c));
        //G[b].push_back(std::make_pair(a, c));
    }

    auto ans = solve(1);

    if(ans.size() == 0) std::cout << -1 << "\n";
    else{
        for(int i = 2; i <= n; i++){
            if(ans[i] >= INF) std::cout << "-1" << "\n";
            else std::cout << ans[i] << "\n";
        }
    }
    return 0;
}

// https://leesh111112.tistory.com/24