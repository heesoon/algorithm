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
    int next = 0;
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

    return answer;
}

void tc1(){
    int N = 5;
    int K = 17;
    int answer = 4;

    if(answer == solution(N, K)){
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