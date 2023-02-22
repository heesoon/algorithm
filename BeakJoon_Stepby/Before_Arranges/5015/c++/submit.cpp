#include <iostream>
#include <vector>
#include <cstring>

std::string pattern;
std::string filename;
int cache[101][101];

bool solve(int pIdx, int sIdx){
    int &ref = cache[pIdx][sIdx];
    if(ref != -1) return ref;

    if(pIdx < pattern.size() && sIdx < filename.size() && pattern[pIdx] == filename[sIdx]){
        return ref = solve(pIdx+1, sIdx+1);
    }

    if(pIdx == pattern.size()){
        return ref = (sIdx == filename.size());
    }

    if(pattern[pIdx] == '*'){
        if(solve(pIdx+1, sIdx) || (sIdx < filename.size() && solve(pIdx, sIdx+1))){
            return ref = true;
        }
    }

    return ref = false;
}

void tc1(){
    int N = 4;
    pattern = "*.*";
    std::string str[N] = {"main.c", "a.out", "readme", "yacc"};

    for(int i = 0; i < N; i++){
        filename = str[i];
        if(solve(0, 0) == true){
            std::cout << filename << std::endl;
        }
    }
}

int main(){
#if 1  
    int N;
    std::cin >> pattern;
    std::cin >> N;
    for(int i = 0; i < N; i++){
        std::cin >> filename;
        std::memset(cache, -1, sizeof(int)*101*101);
        if(solve(0, 0) == true){
            std::cout << filename << std::endl;
        }
    }
#else
    tc1();
#endif
}