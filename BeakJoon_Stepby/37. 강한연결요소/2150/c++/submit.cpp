#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <stack>
#include <limits>

int V, E, num;
std::vector<std::vector<int>> vMap;
std::vector<std::vector<int>> vReverseMap;
std::vector<bool> vVisited;
std::stack<int> sStack;
std::vector<std::vector<int>> vAns;

void buildStack(int cIdx){
    if(vVisited[cIdx] == true) return;
    
    vVisited[cIdx] = true;
    for(const auto &nIdx : vMap[cIdx]) buildStack(nIdx);
    sStack.push(cIdx);
}

void reverseCheckRoutine(int cIdx){
    if(vVisited[cIdx] == true) return;
    
    vVisited[cIdx] = true;
    vAns[num].push_back(cIdx);
    for(const auto &nIdx : vReverseMap[cIdx]) reverseCheckRoutine(nIdx);
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    std::cin >> V >> E;

    vMap = std::vector<std::vector<int>>(V+1);
    vReverseMap = std::vector<std::vector<int>>(V+1);
    vVisited.assign(V+1, false);

    for(int i = 0; i < E; i++){
        int a, b;
        std::cin >> a >> b;
        vMap[a].push_back(b);
        vReverseMap[b].push_back(a);
    }

    for(int i = 1; i <= V; i++){
        buildStack(i);
    }

    std::fill(vVisited.begin(), vVisited.end(), false);

    while(sStack.empty() == false){
        int idx = sStack.top();
        if(vVisited[idx] == false){
            vAns.push_back(std::vector<int>());
            reverseCheckRoutine(idx);
            num++;
        }
        sStack.pop();
    }

    std::cout << num << "\n";

    for(int i = 0; i < num; i++){
        std::sort(vAns[i].begin(), vAns[i].end());
    }
    std::sort(vAns.begin(), vAns.end());

    for(int i = 0; i < num; i++){
        for(const auto &v : vAns[i]){
            std::cout << v << " ";
        }
        std::cout << "-1\n";
    }

    return 0;
}