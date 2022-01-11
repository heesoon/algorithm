#include <iostream>
#include <vector>
#include <cstring>

int N;
int map[101][101];
long long cache[101][101];

long long solution(int y, int x){ 
    if(y >= N || x >= N)      return 0;
    if(y == N-1 && x == N-1)  return 1;

    long long &ret = cache[y][x];
    if(ret != -1)   return ret;
    else            return ret = solution(y+map[y][x], x) + solution(y, x+map[y][x]);
}

int main(){   
    std::cin >> N;    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            std::cin >> map[i][j];
        }
    }

    std::memset(cache, -1, sizeof(cache));
    std::cout << solution(0, 0) << std::endl;

    return 0;
}