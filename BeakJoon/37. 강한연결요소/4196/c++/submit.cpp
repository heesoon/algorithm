#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <stack>
#include <limits>

int id, sccGrpIdx;
std::stack<int> sStack;
std::vector<int> vIdxPool;
std::vector<int> vIndegree;
std::vector<int> vGrpIdxPool;
std::vector<std::vector<int>> vMap;

int solve(int curIdx){
    vIdxPool[curIdx] = ++id;
    sStack.push(curIdx);

    int parentIdx = vIdxPool[curIdx];

    for(const auto &adjIdx : vMap[curIdx]){
        if(vIdxPool[adjIdx] == 0){
            parentIdx = std::min(parentIdx, solve(adjIdx));
        }
        else if(vGrpIdxPool[adjIdx] == 0){
            parentIdx = std::min(parentIdx, vIdxPool[adjIdx]);
        }
    }

    if(parentIdx == vIdxPool[curIdx]){
        while(1){
            int top = sStack.top(); sStack.pop();
            vGrpIdxPool[top] = sccGrpIdx;
            if(top == curIdx) break;
        }

        sccGrpIdx++;
    }

    return parentIdx;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int T, ans = 0;
    std::cin >> T;

    while(T--){
        int N, M;
        std::cin >> N >> M;
        vMap = std::vector<std::vector<int>>(N+1);
        vIdxPool.assign(N+1, 0);
        vIndegree.assign(N+1, 0);
        vGrpIdxPool.assign(N+1, 0);

        for(int i = 0; i < M; i++){
            int a, b;
            std::cin >> a >> b;
            vMap[a].push_back(b);
        }

        id = 0, sccGrpIdx = 1;
        for(int i = 1; i <= N; i++){
            if(vIdxPool[i] == 0){
                solve(i);
            }
        }

        for(int i = 1; i <= N; i++){
            for(const auto &j : vMap[i]){
                if(vGrpIdxPool[i] == vGrpIdxPool[j]) continue;
                vIndegree[vGrpIdxPool[j]]++;
            }
        }

        for(int i = 1; i < sccGrpIdx; i++){
            if(vIndegree[i] == 0) ans++;
        }
    
        std::cout << ans << "\n";

        vMap.clear();
        vIdxPool.clear();
        vGrpIdxPool.clear();
        vIndegree.clear();
    }
    return 0;
}