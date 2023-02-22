#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <limits>

const int INF = std::numeric_limits<int>::max()/2;
int numOfNode, numOfVertex;
std::vector<std::vector<std::pair<int,int>>> G;

std::vector<int> solve(int start){
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> Q;
    std::vector<int> distance(numOfNode+1, INF);
    Q.push(std::make_pair(0, start));
    distance[start] = 0;

    while(!Q.empty()){
        int fWeight = Q.top().first;
        int fNode = Q.top().second;
        Q.pop();

        for(auto p : G[fNode]){
            int nNode = p.first;
            int nWeight = p.second + fWeight;

            if(nWeight < distance[nNode]){
                distance[nNode] = nWeight;
                Q.push(std::make_pair(nWeight, nNode));
            }
        }
    }

    return distance;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int A, B;
    std::cin >> numOfNode >> numOfVertex;
    
    G = std::vector<std::vector<std::pair<int,int>>>(numOfNode+1);

    for(int i = 0; i < numOfVertex; i++){
        int from, to, weight;
        std::cin >> from >> to >> weight;
        G[from].push_back(std::make_pair(to, weight));
        G[to].push_back(std::make_pair(from, weight));
    }

    std::cin >> A >> B;

    auto result1 = solve(1);
    auto result2 = solve(A);
    auto result3 = solve(B);

    int ans = std::min(result1[A] + result2[B] + result3[numOfNode], result1[B] + result3[A] + result2[numOfNode]);
    if(ans >= INF || ans < 0) std::cout << "-1" << "\n";
    else std::cout << ans << "\n";

    return 0;
}