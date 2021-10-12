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

bool is_in_range(int y, int x){
    if((y >= 0 && y < N) && (x >= 0 && x < N)){
        return true;
    }

    return false;
}

bool solve(int y, int x, const std::string &str){
    bool ret = false;

    if(is_in_range(y, x) == false){
        return false;
    }

    if(map[y][x] != str[0]){
        return false;
    }

    if(str.size() == 1){
        return true;
    }

    for(int i = 0; i < 8; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(solve(ny, nx, str.substr(1)) == true){
            return true;
        }
    }

    return ret;
}

int main(){

    for(int i = 0; i < tc.size(); i++){
        bool hasword = false;
        for(int y = 0; y < N; y++){
            for(int x = 0; x < N; x++){
                hasword = solve(y, x, tc[i]);
                if(hasword == true){
                    break;
                }
            }
            if(hasword == true){
                break;
            }
        }

        std::cout << tc[i] << " ";
        if(hasword == true) std::cout << "YES";
        else std::cout << "NO";
        std::cout << std::endl;
    }

    return 0;
}