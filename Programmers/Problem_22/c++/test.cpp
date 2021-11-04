#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getParents(const std::vector<int> &db, int node){
    return db[node];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    std::vector<int> parentDB;
    for(size_t i = 0; i < costs.size(); i++){
        parentDB.emplace_back(i);
    }

    std::sort(costs.begin(), costs.end(), [](const std::vector<int> &a, const std::vector<int> &b){
        return a[2] < b[2];
    });

    for(const auto &v : costs){
        int a = std::min(v[0], v[1]);
        int b = std::max(v[0], v[1]);
        int c = v[2];

        int pa = getParents(parentDB, a);
        int pb = getParents(parentDB, b);

        if(pa == pb){
            continue;
        }
        else{
            parentDB[b] = a;
            answer += c;
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