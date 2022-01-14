#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

std::vector<std::vector<int>> works;

int solve(int n){

}

// perfect matching problem.
int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int n;
    std::cin >> n;

    works.assign(n, std::vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cin >> works[i][j];
        }
    }

    std::cout << solve(n) << "\n";
    return 0;
}