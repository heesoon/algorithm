#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int nextValue(int N, int i){
    int retval = 0;

    if(i == 0){
        retval = N - 1;    
    }
    else if(i == 1){
        retval = N + 1;
    }
    else{
        retval = N*2;
    }

    return retval;
}

int solution(int N, int K) {
    int answer = 0;
    std::queue<std::vector<int>> Q;
    std::vector<bool> visited(K+1, false);
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

        for(int i = 0; i < 3; i++){
            int next = nextValue(curr, i);
            if(visited[next] == false){
                visited[next] = true;
                Q.push({next, depth+1});
            }
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