#include <iostream>
#include <string>
#include <vector>

using namespace std;

#if 0
void print(const std::vector<std::vector<int>> &ar){
    for(int i = 0; i < ar.size(); i++){
        for(int j = 0; j < ar[0].size(); j++){
            std::cout << ar[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
#endif

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, 1));

    for(size_t y = 0; y <= n; y++){
        for(size_t x = 0; x <= m; x++){
            if(x == 0 || y == 0){
                dp[y][x] = 0;
            }
        }
    }

    for(const auto v : puddles){
        int y = v[1];
        int x = v[0];

        dp[y][x] = 0;

        // x == 1
        if(x == 1){
            for(int i = y; i <= n; i++){
                dp[i][x] = 0;
            }
        }

        // y == 1
        if(y == 1){
            for(int i = x; i <= m; i++){
                dp[y][i] = 0;
            }
        }    
    }

    for(size_t y = 2; y <= n; y++){
        for(size_t x = 2; x <= m; x++){
            if(dp[y][x] == 0){
                continue;
            }

            dp[y][x] = (dp[y-1][x] + dp[y][x-1]) % 1000000007;
        }
    }

    return dp[n][m];
}

void tc1(){
	int m = 4;
	int n = 3;
	std::vector<std::vector<int>> puddles = {{2, 2}};

    int answer = solution(m, n, puddles);
    if(answer == 4){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

int main(){
    tc1();
    return 0;
}

// https://hochoon-dev.tistory.com/entry/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EB%93%B1%EA%B5%A3%EA%B8%B8-c
// x = 1, y = 1일 때, 고려를 못함.

// 완전탐색을 DP로 변환시 활용 가능 코드
// https://dailyheumsi.tistory.com/25