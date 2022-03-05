#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

const int N = 9;
std::vector<std::vector<int>> map;
std::vector<std::vector<bool>> col;
std::vector<std::vector<bool>> row;
std::vector<std::vector<bool>> box3x3;

void solve(int cnt){
    if(cnt == 81){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                std::cout << map[i][j] << " ";
            }
            std::cout << "\n";
        }
        exit(0);
    }

    int y = cnt/N;
    int x = cnt%N;

    if(map[y][x]){
        solve(cnt+1);
    }
    else{
        for(int i = 1; i <= N; i++){
            if(col[x][i] == false && row[y][i] == false && box3x3[(y/3)*3 + x/3][i] == false){
                map[y][x] = i;
                col[x][i] = row[y][i] = box3x3[(y/3)*3 + x/3][i] = true;
                solve(cnt+1);
                map[y][x] = 0;
                col[x][i] = row[y][i] = box3x3[(y/3)*3 + x/3][i] = false;
            }
        }
    }
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    map.assign(N, std::vector<int>(N, 0));
    col.assign(N+1, std::vector<bool>(N+1, false));
    row.assign(N+1, std::vector<bool>(N+1, false));
    box3x3.assign(N, std::vector<bool>(N+1, false));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            std::cin >> map[i][j];
            if(map[i][j]){
                row[i][map[i][j]] = true;
                col[j][map[i][j]] = true;
                box3x3[(i/3)*3 + j/3][map[i][j]] = true;
            }
        }
    }

    solve(0);
    return 0;
}