#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int maxDist = 0;
    std::queue<int> Q;
    std::vector<std::vector<int>> G(n+1);
    std::vector<bool> visited(n+1, false);
    std::vector<int> distance(n+1, 0);

    for(const auto &e : edge){
        int from = e[0];
        int to = e[1];

        G[from].push_back(to);
        G[to].push_back(from);
    }

    Q.push(1);
    visited[1] = true;

    while(!Q.empty()){
        int from = Q.front();
        Q.pop();

        for(const auto &to : G[from]){
            if(visited[to] == false){
                visited[to] = true;
                distance[to] = distance[from] + 1;
                maxDist = std::max(distance[to], maxDist);
                Q.push(to);
            }
        }
    }

    answer = std::count_if(distance.begin(), distance.end(), [&](int i){return i == maxDist;});

    return answer;
}

void tc1(){
	int n = 6;
	std::vector<std::vector<int>> edge = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};

    int answer = solution(n, edge);
    if(answer == 3){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

int main(){
    tc1();
    return 0;
}