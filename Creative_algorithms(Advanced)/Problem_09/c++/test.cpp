#include <iostream>
#include <vector>
#include <algorithm>

const int MAX = 200 + 1;
std::vector<std::vector<int>> DT(MAX, std::vector<int>(MAX, 0));

int solution(int n, int m, const std::vector<std::vector<int>> &map) {
    for(int y = 1; y <= n; y++){
        for(int x = 1; x <= m; x++){
            DT[y][x] = map[y][x] + std::max(DT[y-1][x], DT[y][x-1]);
        }
    }

    return DT[n][m];
}

void tc1(){
    int n = 5;
    int m = 4;

    std::vector<std::vector<int>> map = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 0, 0}
    };

    if(4 == solution(n, m, map)){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }

    // print DT
    for(std::vector<std::vector<int>>::size_type y = 0; y <= n; y++){
        for(std::vector<std::vector<int>>::size_type x = 0; x <= m; x++){
            std::cout << DT[y][x] << " ";
        }
        std::cout << std::endl;
    }
}

int main(){
    tc1();
    return 0;
}