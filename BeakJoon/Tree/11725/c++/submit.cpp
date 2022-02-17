#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

int n;
std::vector<int> parentStore;
std::vector<std::vector<int>> tree;
std::vector<bool> visited;

void printParents(){
    for(int i = 2; i <= n; i++){
        std::cout << parentStore[i] << "\n";
    }
}

void solve(int sIdx){
    for(auto it = tree[sIdx].begin(); it != tree[sIdx].end(); it++){
        int nIdx = *it;
        if(visited[nIdx] == false){
            visited[nIdx] = true;
            parentStore[nIdx] = sIdx;
            solve(nIdx);
        }
    }
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    std::cin >> n;
    tree.assign(n+1, std::vector<int>(0, 0));
    parentStore.assign(n+1, 0);
    visited.assign(n+1, false);

    for(int i = 0; i < n-1; i++){
        int f, t;
        std::cin >> f >> t;
        tree[f].push_back(t);
        tree[t].push_back(f);
    }

    visited[1] = true;
    solve(1);
    printParents();
    return 0;
}