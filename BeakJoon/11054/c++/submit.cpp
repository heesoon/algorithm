#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> LLIS;
std::vector<int> RLIS;
std::vector<int> S;

int solve(int n){
    int ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(S[j] < S[i]){
                RLIS[i] = std::max(RLIS[i], RLIS[j]+1);
            }
        }
    }

    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j > i; j--){
            if(S[j] < S[i]){
                LLIS[i] = std::max(LLIS[i], LLIS[j]+1);
            }
        }
    }

#if 0
    for(int i = 0; i < n; i++){
        std::cout << RLIS[i] << " ";
    }
    std::cout << std::endl;
    for(int i = 0; i < n; i++){
        std::cout << LLIS[i] << " ";
    }
    std::cout << std::endl;
#endif

    for(int i = 0; i < n; i++){
        ans = std::max(ans, RLIS[i] + LLIS[i] - 1);
    }

    return ans;
}

int main(){
    int n;
    std::cin >> n;
    LLIS.assign(n, 1);
    RLIS.assign(n, 1);
    S.assign(n, 0);

    for(int i = 0; i < n; i++){
        std::cin >> S[i];
    }

    std::cout << solve(n) << std::endl;
}