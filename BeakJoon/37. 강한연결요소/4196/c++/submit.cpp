#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <stack>
#include <limits>

int id, ans;
std::stack<int> sStack;
std::vector<int> vIdxPool;
std::vector<bool> vIsFinished;
std::vector<std::vector<int>> vMap;

int solve(int curIdx){
    vIdxPool[curIdx] = ++id;
    sStack.push(curIdx);

    int parentIdx = vIdxPool[curIdx];

    for(const auto &adjIdx : vMap[curIdx]){
        if(vIdxPool[adjIdx] == 0){
            parentIdx = std::min(parentIdx, solve(adjIdx));
        }
        else if(vIsFinished[adjIdx] == false){
            parentIdx = std::min(parentIdx, vIdxPool[adjIdx]);
        }
    }

    if(parentIdx == vIdxPool[curIdx]){
        while(1){
            int top = sStack.top(); sStack.pop();
            vIsFinished[top] = true;
            if(top == curIdx) break;
        }

        ans++;
    }

    return parentIdx;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;

    while(T--){
        int N, M;
        std::cin >> N >> M;
        vMap = std::vector<std::vector<int>>(N+1);
        vIdxPool.assign(N+1, 0);
        vIsFinished.assign(N+1, false);

        for(int i = 0; i < M; i++){
            int a, b;
            std::cin >> a >> b;
            vMap[a].push_back(b);
        }

        id = 0, ans = 0;
        for(int i = 1; i <= N; i++){
            if(vIdxPool[i] == 0){
                solve(i);
            }
        }

        std::cout << ans << "\n";

        vMap.clear();
        vIdxPool.clear();
        vIsFinished.clear();
    }
    return 0;
}