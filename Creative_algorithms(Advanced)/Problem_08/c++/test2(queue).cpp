#include <iostream>
#include <vector>
#include <queue>

int solution(int start, int end, const std::vector<int> &abilities) {
    std::queue<std::vector<int>> Q;
    std::vector<bool> visited(1000 + 1, false);
    Q.push({start, 0});
    visited[start] = true;

    while(!Q.empty()){
        int node = Q.front()[0];
        int time = Q.front()[1];
        Q.pop();

        if(node == end){
            return time;
        }

        for(const auto &a : abilities){
            int newNode = node + a;
            if(visited[newNode] == false && newNode <= end){
                visited[newNode] = true;
                Q.push({newNode, time+1});
            }
        }
    }
}

void tc1(){
    int start = 1;
    int end = 15;
    std::vector<int> abilities{2, 5, 7};

    if(2 == solution(start, end, abilities)){
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