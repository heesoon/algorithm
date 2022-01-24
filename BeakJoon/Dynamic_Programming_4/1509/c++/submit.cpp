#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

const int L = 2'501;
std::vector<std::vector<int>> DT(L, std::vector<int>(L, -1));
std::vector<int> DT2(L, 0);
std::string inputStr;

int is_pelind_room(int s, int e){
    int &ret = DT[s][e];
    if(ret != -1) return ret;

    if(inputStr[s] != inputStr[e]){
        return ret = 0;
    }
    if(s >= e){
        return ret = 1;
    }

    return ret = is_pelind_room(s+1, e-1);
}

int solve(){
    DT2[0] = 0;
    for(int i = 1; i <= inputStr.size(); i++){
        DT2[i] = DT2[i-1] + 1;
        for(int j = 1; j < i; j++){
            if(is_pelind_room(j, i) == false) continue;
            DT2[i] = std::min(DT2[j], DT2[j-1]+1);
        }
    }

    return DT2[inputStr.size()];
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);

    std::cin >> inputStr;

    std::cout << solve() << "\n";
    return 0;
}

// https://justicehui.github.io/ps/2019/09/21/BOJ1509/