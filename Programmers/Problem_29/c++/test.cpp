#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool dfs(int idx, vector<vector<int>> computers){
    if(computers[idx][idx] == 0) return false;

    computers[idx][idx] = 0;

    for(int i = 0; i < computers.size(); i++){
        if(computers[idx][i] == 1){
            dfs(i, computers);
        } 
    }

    return true;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for(int i = 0; i < n; i++){
        if(computers[i][i] && dfs(i, computers)){
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