#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <limits>

const int INF = std::numeric_limits<int>::max()/2;
int numOfNode, numOfVertex;
std::vector<int> distance;
std::vector<bool> visited;
std::vector<std::vector<std::pair<int,int>>> G;

void printAns(){
    for(int i = 1; i <= numOfNode; i++){
        if(distance[i] == INF) std::cout << "INF" << " ";
        else std::cout << distance[i] << " ";
    }
}

void solve(int start){
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> Q;
    Q.push(std::make_pair(0, start));
    distance[start] = 0;

    while(!Q.empty()){
        int fWeight = Q.top().first;
        int fNode = Q.top().second;
        Q.pop();

        for(auto p : G[fNode]){
            int nNode = p.first;
            int weight = p.second;

            if(visited[nNode] == false){
                visited[nNode] = true;
                //distance[nNode] = std::min(distance[nNode], fWeight+weight);
                if(distance[nNode] > fWeight+weight){
                    distance[nNode] = fWeight+weight;
                }
                Q.push(std::make_pair(distance[nNode], nNode));
            }
        }
    }
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int startNode;
    std::cin >> numOfNode >> numOfVertex;
    std::cin >> startNode;
    
    G = std::vector<std::vector<std::pair<int,int>>>(numOfNode+1);
    distance.assign(numOfNode+1, INF);
    visited.assign(numOfNode+1, false);

    for(int i = 0; i < numOfVertex; i++){
        int from, to, weight;
        std::cin >> from >> to >> weight;
        G[from].push_back(std::make_pair(to, weight));
    }

    solve(startNode);
    printAns();

    return 0;
}