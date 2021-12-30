#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> DT;

int solve(int n){
    int a;
    for(int i = 1; i <= n; i++){
        std::cin >> a;
        if(i == 1){
            DT[i] = a;
            continue;
        }

        if(DT[i-1] < 0){
            DT[i] = a;
        }
        else{
            DT[i] = DT[i-1] + a;
        }
    }
    
    auto begin = DT.begin();
    std::advance(begin, 1);

    return *std::max_element(begin, DT.end());
}

int main(){
    int n;
    std::cin >> n;
    DT.assign(n+1, 0);
    std::cout << solve(n) << std::endl;
}

// other reference : https://sihyungyou.github.io/baekjoon-1912/