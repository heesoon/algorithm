#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <limits>

int n, m;
std::vector<int> G[101];
std::vector<bool> visited(101, false);
int solve(int node){
    int cnt = 0;
    std::queue<int> Q;
    Q.push(node);
    visited[node] = true;

    while(!Q.empty()){
        int fnode = Q.front();
        Q.pop();
        for(auto it = G[fnode].begin(); it != G[fnode].end(); it++){
            int nextNode = *it;
            if(visited[nextNode] == false){
                visited[nextNode] = true;
                cnt++;
                Q.push(nextNode);
            }
        }
    }

    return cnt;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    std::cin >> n >> m;
    for(int i = 0; i < m; i++){
        int from, to;
        std::cin >> from >> to;
        G[from].push_back(to);
        G[to].push_back(from);
    }

    std::cout << solve(1) << "\n";
    return 0;
}