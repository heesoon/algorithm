#include <iostream>
#include <algorithm>
#include <limits>

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int C;
    std::cin >> C;

    while(C--){
        int N, cnt = 0;
        int sum = 0;
        std::cin >> N;
        std::vector<int> vScore(N, 0);
        for(int i = 0; i < N; i++){
            std::cin >> vScore[i];
            sum += vScore[i];
        }

        int avg = sum/N;

        for(auto x : vScore){
            if(x > avg){
                cnt++;
            }
        }

        std::cout << std::fixed;
        std::cout.precision(3);
        std::cout << ((double)cnt)/N*100 << "%" << "\n";
    }
    return 0;
}