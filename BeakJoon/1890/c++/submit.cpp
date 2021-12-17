#include <iostream>
#include <vector>

int solution(int N, const std::vector<std::vector<int>> &map) {
    int next;
    std::vector<std::vector<long long>> DT(101, std::vector<long long>>(101, 0));
    DT[0][0] = 1;

    for(int y = 0; y < N; y++){
        for(int x = 0; x < N; x++){
            next = map[y][x];
            if(DT[y][x] == 0 || (y == N-1 && x == N-1)) continue;
            if(y+next < N) DT[y+next][x] += DT[y][x];
            if(x+next < N) DT[y][x+next] += DT[y][x];
        }
    }

    return DT[N-1][N-1];
}

int main(){   
    int N;

    std::cin >> N;
    std::vector<std::vector<int>> map(N, std::vector<int>(N, 0));
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            std::cin >> map[i][j];
        }
    }

    std::cout << solution(N, map) << std::endl;

    return 0;
}