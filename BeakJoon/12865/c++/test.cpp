#include <iostream>
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

    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> Q;
    //std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> Q;
    std::vector<bool> visited(100'001, false);
    //Q.push(make_pair(0, N));
    Q.push({0, N});
    visited[N] = true;

    while(!Q.empty()){
        auto front = Q.top();
        int depth = front[0];
        int curr = front[1];
        //int depth = Q.top().first;
        //int curr = Q.top().second;        
        Q.pop();

        if(curr == K){
            answer = depth;
            break;
        }

        next = curr*2;
        if(valid(next, visited)){
            visited[next] = true;
            Q.push({depth, next});
            //Q.push(make_pair(depth, next));
        }

        next = curr - 1;
        if(valid(next, visited)){
            visited[next] = true;
            Q.push({depth + 1, next});
            //Q.push(make_pair(depth+1, next));
        }

        next = curr + 1;
        if(valid(next, visited)){
            visited[next] = true;
            Q.push({depth + 1, next});
            //Q.push(make_pair(depth+1, next));
        }
    }

    return answer;
}


void tc1(){
    int N = 5;
    int K = 17;
    int answer = 2;

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