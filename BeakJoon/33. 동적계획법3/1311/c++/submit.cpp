#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <limits>

std::vector<std::vector<int>> works;
std::vector<std::vector<int>> DT;
int n;

int solve(int idx, int visited){
    if(visited == (1 << n) - 1){
        return 0;
    }

    int &ret = DT[idx][visited];
    if(ret != -1){
        return ret;
    }

    ret = std::numeric_limits<int>::max()/2;

    for(int i = 0; i < n; i++){
        if(visited & (1 << i)) continue;

        ret = std::min(ret, solve(idx+1, visited | (1 << i)) + works[idx][i]);
    }

    return ret;
}

// perfect matching problem.
int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cin >> n;

    works.assign(n, std::vector<int>(n, 0));
    DT.assign(21, std::vector<int>(2 << n, -1));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cin >> works[i][j];
        }
    }

    std::cout << solve(0, 0) << "\n";
    return 0;
}

//https://technicolour.tistory.com/14