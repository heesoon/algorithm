#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

const int L = 1'001;
int N, M;
int dy[3] = {0, 1, 0};
int dx[3] = {1, 0, -1};

std::vector<std::vector<int>> DT;
std::vector<std::vector<int>> map;
std::vector<std::vector<bool>> visited;

bool in_range(int y, int x){
    if((y >= 0 && y < N) && (x >= 0 && x < M)){
        return true;
    }
    return false;
}

int solve(int y, int x){
    int &ret = DT[y][x];
    if(ret != -1) return ret;

    if(y == N-1 && x == M-1){
        return ret = map[y][x];
    }

    ret = 0;
    for(int i = 0; i < 3; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(visited[ny][nx] == false && in_range(ny, nx) == true){
            ret = std::max(ret, solve(ny, nx) + map[y][x]);
        }
    }

    return ret;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    DT.assign(L, std::vector<int>(L, -1));
    map.assign(L, std::vector<int>(L, 0));
    visited.assign(L, std::vector<bool>(L, false));

    std::cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            std::cin >> map[i][j];
        }
    }

    std::cout << solve(0, 0) << "\n";
    return 0;
}