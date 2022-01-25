#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

const int L = 1'001;
int N, M;
int dx[3] = {1, 0, -1}, dy[3] = {0, 1, 0};

std::vector<std::vector<std::vector<int>>> DT;
std::vector<std::vector<int>> map;

bool in_range(int y, int x){
    if((y >= 0 && y < N) && (x >= 0 && x < M)){
        return true;
    }
    return false;
}

int solve(int y, int x, int d){
    int &ret = DT[y][x][d];
    if(ret != -1) return ret;

    if(y == N-1 && x == M-1){
        return ret = map[y][x];
    }

    ret = std::numeric_limits<int>::min()/2;
    for(int i = 0; i < 3; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if((d+2)%4 == i) continue;
        if(in_range(ny, nx) == false) continue;
        ret = std::max(ret, solve(ny, nx, i) + map[y][x]);
    }

    return ret;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    DT.assign(L, std::vector<std::vector<int>>(L, std::vector<int>(3, -1)));
    map.assign(L, std::vector<int>(L, 0));

    std::cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            std::cin >> map[i][j];
        }
    }

    std::cout << solve(0, 0, 1) << "\n";
    return 0;
}

https://degurii.tistory.com/182