#include <iostream>
#include <string>
#include <vector>

const int N = 5;
char map[N][N] = {
    {'U', 'R', 'L', 'P', 'M'},
    {'X', 'P', 'R', 'E', 'T'},
    {'G', 'I', 'A', 'E', 'T'},
    {'X', 'T', 'N', 'Z', 'Y'},
    {'X', 'O', 'Q', 'R', 'S'}
};

std::vector<std::string> tc = {
    "PRETTY",
    "GIRL",
    "REPEAT",
    "KARA",
    "PANDORA",
    "GIAZAPX"
};

int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int v[N][N];

bool in_map(int y, int x){
    if((y >= 0 && y < N) && (x >= 0 && x < N)){
        return true;
    }

    return false;
}

int solve(int idx, int y, int x, const std::string &str){
    int r = 0;
    if(idx == str.size()){
        r = 1;
    }

    for(int i = 0; i < 8; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(in_map(ny, nx) == true && v[ny][nx] == 0){
            if(str[idx] == map[ny][nx]){
                v[ny][nx] = 1;
                r += solve(idx+1, ny, nx, str);
                v[ny][nx] = 0;
            }
        }
    }

    return r;
}

int main(){
    for(auto &str : tc){
        int result = 0;
        for(int y = 0; y < N; y++){
            for(int x = 0; x < N; x++){
                if(str[0] == map[y][x]){
                    v[y][x] = 1;
                    result += solve(1, y, x, str);
                    v[y][x] = 0;
                }
            }
        }
        std::cout << str << " ";
        if(result > 0) std::cout << "YES";
        else std::cout << "NO";
        std::cout << "\n";
    }

    return 0;
}