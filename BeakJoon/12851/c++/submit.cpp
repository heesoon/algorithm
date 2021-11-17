#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define LIMIT 100'000

void solution(int N, int K) {
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
        if(next >= 0 && visited[next] == false){
            visited[next] = true;
            Q.push({next, depth + 1});
        }

        next = curr + 1;
        if(next <= LIMIT && visited[next] == false){
            visited[next] = true;
            Q.push({next, depth + 1});
        }

        next = curr*2;
        if(next <= LIMIT && visited[next] == false){
            visited[next] = true;
            Q.push({next, depth + 1});
        }
    }

    std::cout << minCost << std::endl;
    std::cout << minPathCnt << std::endl;
}


int main(){   
    int N, K;
    std::cin >> N >> K;

    solution(N, K);

    return 0;
}