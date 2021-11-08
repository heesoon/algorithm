#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int nn(int N, int idx){
    int nn = N;
    for(int i = 1; i < idx; i++){
        nn = nn * 10 + N;
    }

    return nn;
}

int solution(int N, int number) {
    int answer = -1;

    if(N == number){
        return 1;
    }
    
    std::vector<std::unordered_set<int>> dp(9);

    dp[1].insert(N);
    for(size_t k = 2; k < 9; k++){
        for(size_t i = 0; i < k; i++){
            for(size_t j = 0; j < k; j++){
                if(i + j != k) continue;
                    for(const auto &a : dp[i]){
                        for(const auto &b : dp[j]){
                            dp[k].insert(a+b);
                            dp[k].insert(a*b);
                            if(a - b > 0) dp[k].insert(a-b);
                            if(a / b > 0) dp[k].insert(a/b);
                            dp[k].insert(nn(N, k));
                        }
                    }
            }
        }

        if(dp[k].find(number) != dp[k].end()){
            return k;
        }
    }

    return answer;
}

void tc1(){
	int N = 5;
	int number = 12;

    int answer = solution(N, number);
    if(answer == 4){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
	int N = 2;
	int number = 11;

    int answer = solution(N, number);
    if(answer == 3){
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