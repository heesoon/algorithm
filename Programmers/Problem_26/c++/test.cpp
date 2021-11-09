#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(const std::vector<std::vector<int>> &ar){
    for(int i = 0; i < ar.size(); i++){
        for(int j = 0; j < ar[0].size(); j++){
            std::cout << ar[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

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
        dp[v[1]][v[0]] = 0;
    }

    for(size_t y = 1; y <= n; y++){
        for(size_t x = 1; x <= m; x++){
            if(dp[y][x] == 0){
                continue;
            }

            dp[y][x] = dp[y-1][x] + dp[y][x-1];
        }
    }

    answer = dp[n][m] % 1'000'000'007;
    //std::cout << answer << std::endl;
    
    //print(dp);
    return answer;
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