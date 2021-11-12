#include <iostream>
#include <string>
#include <vector>

using namespace std;

std::vector<int> visited;
void dfs(int idx, vector<vector<int>> computers){
    for(int next = 0; next < computers.size(); next++){
        if(computers[idx][next] == 1 && visited[next] == 0){
            visited[next] = 1;
            dfs(next, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    visited.assign(n, 0);
    for(int i = 0; i < n; i++){
        if(visited[i] == 0){
            dfs(i, computers);
            answer++;
        }
    }

    return answer;
}

void tc1(){
	int n = 3;
	std::vector<std::vector<int>> computers = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};

    int answer = solution(n, computers);
    if(answer == 2){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
	int n = 3;
	std::vector<std::vector<int>> computers = {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};

    int answer = solution(n, computers);
    if(answer == 1){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

int main(){
    tc1();
	tc2();
    return 0;
}