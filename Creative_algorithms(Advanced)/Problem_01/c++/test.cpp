#include <iostream>
#include <vector>

using namespace std;

const int MAX = 30 + 1;

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

void tc1(){
    int n = 5;
    int k = 1;

    long long answer = solution(n, k);
    if(answer == 5){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
    int n = 10;
    int k = 5;

    long long answer = solution(n, k);
    if(answer == 252){
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