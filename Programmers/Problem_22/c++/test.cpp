#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getParents(std::vector<int> &db, int node){
    if(node == db[node]){
        return node;
    }

    return db[node] = getParents(db, db[node]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    std::vector<int> parentDB;
    for(size_t i = 0; i < n; i++){
        parentDB.emplace_back(i);
    }

    std::sort(costs.begin(), costs.end(), [](const std::vector<int> &a, const std::vector<int> &b){
        return a[2] < b[2];
    });

    for(const auto &v : costs){
        int a = getParents(parentDB, v[0]);
        int b = getParents(parentDB, v[1]);

        if(a != b){
            parentDB[b] = a;
            answer += v[2];
        }
    }

    return answer;
}

void tc1(){
    int n = 4;
	std::vector<std::vector<int>> costs = {{0,1,1}, {0,2,2}, {1,2,5}, {1,3,1}, {2,3,8}};

    int answer = solution(n, costs);
    if(answer == 4){
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