#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100'000 + 1;

long long solution(int n, int m) {
    long long answer = 0;
    std::vector<long long> dp(MAX, 0);

    // 왜 dp[0] = 1로 넣어줘야지만 홀짝으로 분리시 정상값을 얻어옮은 생각 필요
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;

#if 0
    for(int i = 3; i <= n; i++){
        dp[i] = dp[i-1] + 2*dp[i-2];
    }
#else
    for(int i = 3; i <= n; i++){
        if(i%2){
            // odd
            dp[i] = dp[i/2]*dp[i/2 + 1] + 2*dp[i/2 - 1]*dp[i/2];
            //std::cout << i << " , " << dp[i] << std::endl;
        }
        else{
            // even
            dp[i] = dp[i/2]*dp[i/2] + 2*dp[i/2 - 1]*dp[i/2 - 1];
            //std::cout << i << " , " << dp[i] << std::endl;
        }
    }
#endif
    //std::cout << n << " , " << dp[n] << std::endl;
    return answer = dp[n]%m;
}

void tc1(){
    int n = 8;
    int m = 100;

    long long answer = solution(n, m);
    if(answer == 71){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
    int n = 8;
    int m = 2;

    long long answer = solution(n, m);
    if(answer == 1){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

int main(){
    tc1();
    tc2();
    return 0;
}