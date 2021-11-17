#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool valid(int n, const std::vector<bool> &visited){
    if(n < 0 || n > 100'000 || visited[n]){
        return false;
    }

    return true;
}

std::vector<int> solution(int N, int K) {
    int next = 0;
    int minCost = 0;
    int minPathCnt = 0;
    std::queue<std::vector<int>> Q;
    std::vector<bool> visited(100'001, false);
    Q.push({N, 0});
    visited[N] = true;

    while(!Q.empty()){
        auto front = Q.front();
        int curr = front[0];
        int depth = front[1];
        Q.pop();

        visited[K] = false;

        if(minCost == depth && curr == K){
            minPathCnt++;
        }

        if(!minCost && curr == K){
            minCost = depth;
            minPathCnt++;
        }

        next = curr - 1;
        if(valid(next, visited)){
            visited[next] = true;
            Q.push({next, depth + 1});
        }

        next = curr + 1;
        if(valid(next, visited)){
            visited[next] = true;
            Q.push({next, depth + 1});
        }

        next = curr*2;
        if(valid(next, visited)){
            visited[next] = true;
            Q.push({next, depth + 1});
        }     
    }

    std::cout << minCost << " , " << minPathCnt << std::endl;
    return {minCost, minPathCnt};
}

void tc1(){
    int N = 5;
    int K = 17;

    if(std::vector<int>{4, 2} == solution(N, K)){
        std::cout << "success" << std::endl;
    }
    else{
        std::cout << "fail" << std::endl;
    }
}

int main(){
    tc1();
    return 0;
}