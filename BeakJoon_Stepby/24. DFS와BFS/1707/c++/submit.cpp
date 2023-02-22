#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <limits>

int v, e;
std::vector<std::vector<int>> G;
std::vector<int> visited; // 0 : Not visited, 1 : RED, 2 : BLACK

void printGraph(){
    for(int i = 0; i <= v; i++){
        std::cout << i << " -> ";
        for(auto it = G[i].begin(); it != G[i].end(); it++){
            std::cout << *it << " ";
        }
        std::cout << "\n";
    }
}

bool check(){
    for(int i = 1; i <= v; i++){
        for(auto it = G[i].begin(); it != G[i].end(); it++){
            int j = *it;
            if(visited[i] == visited[j]){
                return false;
            }
        }
    }
    return true;
}

void solve(int start){
    std::queue<std::pair<int,int>> Q;
    Q.push(std::make_pair(start, 1));

    while(!Q.empty()){
        int fnode = Q.front().first;
        int fcolor = Q.front().second;
        Q.pop();

        for(auto it = G[fnode].begin(); it != G[fnode].end(); it++){
            int nIdx = *it;
            int nColor = 3 - fcolor;
            if(visited[nIdx] == 0){
                visited[nIdx] = 3 - fcolor;
                Q.push(std::make_pair(nIdx, nColor));
            }
        }
    }
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int k;
    std::cin >> k;
    for(int i = 0; i < k; i++){
        std::cin >> v >> e;
        visited.assign(v+1, 0);
        G.assign(v+1, std::vector<int>(0, 0));
        for(int j = 0; j < e; j++){
            int f, t;
            std::cin >> f >> t;
            G[f].push_back(t);
            G[t].push_back(f); // 이거 안 넣어줘서 삽질함.
        }
        // 아래 코드도 필요. 모든 시작부분을 확인해야 함. 단순히 start 한 포인트에서만 하면 37%에서 틀림.
        for(int n = 1; n <= v; n++){
            if(visited[n] == 0){
                solve(n);
            }
        }
        if(check() == true) std::cout << "YES" << "\n";
        else std::cout << "NO" << "\n";
        visited.clear();
        G.clear();
    }
    return 0;
}