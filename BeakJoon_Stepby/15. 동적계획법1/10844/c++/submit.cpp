#include <iostream>
#include <algorithm>

const int MAX = 101;
long long DT[MAX][10];

long long solve(int n){
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 10; j++){
            if(i == 1){
                if(j != 0) DT[i][j] = 1;
            }
            else{
                if(j == 0){
                    DT[i][j] = DT[i-1][j+1] % 1'000'000'000;
                }
                else if(j == 9){
                    DT[i][j] = DT[i-1][j-1] % 1'000'000'000;
                }
                else{
                    DT[i][j] = (DT[i-1][j-1] + DT[i-1][j+1]) % 1'000'000'000;
                }
            }
        }
    }

    for(int i = 0; i < 10; i++){
        ans += DT[n][i];
    }

    return ans % 1'000'000'000;
}

int main(){
    int n;
    std::cin >> n;
    std::fill((long long *)DT, (long long*)DT+(MAX*10), 0);
    std::cout << solve(n) << std::endl;
    return 0;
}