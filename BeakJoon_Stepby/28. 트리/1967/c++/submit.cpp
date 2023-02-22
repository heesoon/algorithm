#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <limits>

int n;
std::vector<bool> visited;
std::vector<std::vector<std::pair<int,int>>> G;

std::pair<int,int> solve(int node, int dist){
    auto ans = std::make_pair(node, dist);
    if(visited[node] == true){
        return std::make_pair(1, 0);
    }

    visited[node] = true;

    for(auto it = G[node].begin(); it != G[node].end(); it++){
        int nNode = (*it).first;
        int nDist = (*it).second;
//        if(visited[nNode] == false){
            auto tmp = solve(nNode, dist+nDist);
            if(tmp.second > ans.second){
                ans.second = tmp.second;
                ans.first = tmp.first;
            }
//        }
    }

    return ans;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    std::cin >> n;

    G = std::vector<std::vector<std::pair<int,int>>>(n+1);
    visited.assign(n+1, false);

    for(int i = 0; i < n-1; i++){
        int f, t, d;
        std::cin >> f >> t >> d;
        G[f].push_back(std::make_pair(t, d));
        G[t].push_back(std::make_pair(f, d));

    }

    auto ans = solve(1, 0);
    std::fill(visited.begin(), visited.end(), false);
    ans = solve(ans.first, 0);

    std::cout << ans.second << "\n";
    return 0;
}