#include <iostream>
#include <vector>
#include <cstring>

std::vector<std::vector<int>> map;
long long cache[101][101];

long long solution(int y, int x){ 
    if(y >= map.size() || x >= map.size())      return 0;
    if(y == map.size()-1 && x == map.size()-1)  return 1;

    long long &ret = cache[y][x];
    if(ret != -1)   return ret;
    else            return ret = solution(y+map[y][x], x) + solution(y, x+map[y][x]);
}

void tc1(){
    map.assign({
        {2, 3, 3, 1},
        {1, 2, 1, 3},
        {1, 2, 3, 1},
        {3, 1, 1, 0}
    });

    std::memset(cache, -1, sizeof(cache));

    if(3 == solution(0, 0)){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }

    map.clear();
}

int main(){
    tc1();
    return 0;
}