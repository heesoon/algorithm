#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <limits>

std::vector<std::vector<int>> works;
std::vector<int> DT;

int solve(int s, int n){
    int ret = 0;

    ret = 

    return ret;
}

// perfect matching problem.
int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    works.assign(n, std::vector<int>(n, 0));
    DT.assign(2 << n, -1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cin >> works[i][j];
        }
    }

    std::cout << solve(0, n) << "\n";
    return 0;
}