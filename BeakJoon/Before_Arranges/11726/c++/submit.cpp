#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000 + 1;

int solution(int n) {
    std::vector<int> dp(MAX, 0);

    // 왜 dp[0] = 1로 넣어줘야지만 홀짝으로 분리시 정상값을 얻어옮은 생각 필요
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 10'007;
    }

    return dp[n];
}

int main(){
    int n;
    std::cin >> n;

    std::cout << solution(n) << std::endl;
    return 0;
}