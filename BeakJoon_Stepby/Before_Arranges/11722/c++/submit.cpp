#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> S;
std::vector<int> DT;

int solve(int n){
    for(int i = 0; i < n; i++){
        std::cin >> S[i];
        DT[i] = 1;
        for(int j = 0; j < i; j++){
            if(S[i] < S[j]){
                DT[i] = std::max(DT[i], DT[j]+1);
            }
        }
    }
 
    return *std::max_element(DT.begin(), DT.end());
}

int main(){
    int n;
    std::cin >> n;
    DT.assign(n, 0);
    S.assign(n, 0);
    std::cout << solve(n) << std::endl;
    return 0;
}