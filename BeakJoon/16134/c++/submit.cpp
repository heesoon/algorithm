#include <iostream>
#include <vector>

using namespace std;

long long solution(int n, int k) {
    std::vector<std::vector<long long>> dp(n+1, std::vector<long long>(n+1, 0));
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;

    if(n == k){
        return 1;
    }
    else if(k == 1){
        return n;
    }
    else{
        for(int i = 2; i <= n; i++){
            for(int j = 0; j <= k; j++){
                if(i == j){
                    dp[i][j] = 1;
                }
                else if(j == 0){
                    dp[i][j] = 1;
                }
                else if(j == 1){
                    dp[i][j] = i;
                }
                else if(i > j){
                    dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % (1000'000'000 + 7);
                }
            }
        }
    }

    return dp[n][k];
}

int main(){
    int n, k;

    std::cin >> n >> k;
    std::cout << solution(n, k) << std::endl;
    return 0;
}