#include <iostream>
#include <vector>

using namespace std;

const int MAX = 30;

long long solution(int n, int k) {
    long long answer;
    std::vector<std::vector<long long>> dp(MAX, std::vector<long long>(MAX, 0));
    
    if(n == k){
        return 1;
    }

    if(k == 1){
        return n;
    }

    dp[1][1] = 1;
    dp[1][0] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            if(i == j){
                dp[i][j] = 1;
            }
            else if(j == 1){
                dp[i][j] = i;
            }
            else if(i > j){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
    }

    return answer = dp[n][k];
}

int main(){   
    int tc, n, k;

    std::cin >> tc;

    for(int i = 0; i < tc; i++){
        std::cin >> k >> n;
        std::cout << solution(n, k) << std::endl;
    }

    return 0;
}