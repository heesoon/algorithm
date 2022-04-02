// Tarjan Algorithm

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <stack>
#include <limits>

int V, E, id;
std::stack<int> sStack;
std::vector<int> vIdxPool;
std::vector<bool> vIsFinished;
std::vector<std::vector<int>> vMap;
std::vector<std::vector<int>> vAns;

int solve(int cIdx){
    vIdxPool[cIdx] = ++id;
    sStack.push(cIdx);

    int parent = vIdxPool[cIdx];
    for(const auto &nIdx : vMap[cIdx]){
        if(vIdxPool[nIdx] == 0){
            parent = std::min(parent, solve(nIdx));
        }
        else if(vIsFinished[nIdx] == false){
            parent = std::min(parent, vIdxPool[nIdx]);
        }
    }

    if(parent == vIdxPool[cIdx]){
        std::vector<int> scc;
        while(1){
            int top = sStack.top(); sStack.pop();
            scc.push_back(top);
            vIsFinished[top] = true;
            if(top == cIdx) break;
        }
        vAns.push_back(scc);
    }

    return parent;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    std::cin >> V >> E;

    vMap = std::vector<std::vector<int>>(V+1);
    vIdxPool.assign(V+1, 0);
    vIsFinished.assign(V+1, false);

    for(int i = 0; i < E; i++){
        int a, b;
        std::cin >> a >> b;
        vMap[a].push_back(b);
    }

    for(int i = 1; i <= V; i++){
        if(vIdxPool[i] == 0) solve(i);
    }

    for(int i = 0; i < vAns.size(); i++){
        std::sort(vAns[i].begin(), vAns[i].end());
    }
    std::sort(vAns.begin(), vAns.end());

    std::cout << vAns.size() << "\n";

    for(int i = 0; i < vAns.size(); i++){
        for(const auto &v : vAns[i]){
            std::cout << v << " ";
        }
        std::cout << "-1\n";
    }

    return 0;
}