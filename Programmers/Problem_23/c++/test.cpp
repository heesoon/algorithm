#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;

    std::sort(routes.begin(), routes.end(), [](const std::vector<int> &a, const std::vector<int> &b){
        return a[0] < b[0];
    });

    int cpos = routes[0][1];

    for(int i = 1; i < routes.size(); i++){
        if(routes[i][1] < cpos){
            cpos = routes[i][1];
        }
        else if(routes[i][0] > cpos){
            answer++;
            cpos = routes[i][1];
        }
    }

    return answer;
}

void tc1(){
	std::vector<std::vector<int>> routes = {{-20,-15}, {-14,-5}, {-18,-13}, {-5,-3}};

    int answer = solution(routes);
    if(answer == 2){
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

/*
#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> a, vector<int> b) { return a[1] < b[1]; }

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int limit = -30001;
    sort(routes.begin(), routes.end(), cmp);
    for(int i = 0; i < routes.size(); i++){
        if(limit < routes[i][0]){
            answer++;
            limit = routes[i][1];
        }
    }
    return answer;
}
*/