#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

int V, E;
const int INF = std::numeric_limits<int>::max()/2;
std::vector<std::vector<int>> map;
std::vector<int> distance;
std::vector<bool> visited;
std::vector<int> S;

void dijkstra(int start){

}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int start;
    std::cin >> V >> E;
    std::cin >> start;

    map.assign(V+1, std::vector<int>(V+1, INF));
    distance.assign(V+1, INF);
    visited.assign(V+1, INF);

    distance[start] = 0;
    visited[start] = true;
    S.push_back(start);

    for(int i = 0; i <= V; i++){
        map[i][i] = 0;
    }

    for(int i = 0; i < E; i++){
        int from, to, weight;
        std::cin >> from >> to >> weight;
        map[from][to] = map[to][from] = weight;
    }
    return 0;
}