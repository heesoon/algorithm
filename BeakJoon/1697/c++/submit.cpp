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

int solution(int N, int K) {
    int answer = 0;
    std::queue<std::vector<int>> Q;
    std::vector<bool> visited(100'001, false);
    Q.push({N, 0});
    visited[N] = true;

    while(!Q.empty()){
        auto front = Q.front();
        int curr = front[0];
        int depth = front[1];
        Q.pop();

        if(curr == K){
            answer = depth;
            break;
        }

        if(valid(curr - 1, visited)){
            visited[curr - 1] = true;
            Q.push({curr - 1, depth + 1});
        }

        if(valid(curr + 1, visited)){
            visited[curr + 1] = true;
            Q.push({curr + 1, depth + 1});
        }

        if(valid(curr * 2, visited)){
            visited[curr * 2] = true;
            Q.push({curr * 2, depth + 1});
        }        
    }

    return answer;
}

int main(){   
    int N, K;
    std::cin >> N >> K;

    std::cout << solution(N, K);
    return 0;
}