#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>
#include <cmath>

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int N;
    double sum = 0;
    int maxCnt = 0, maxIdx;
    std::cin >> N;

    std::vector<int> vNums(N);
    std::vector<int> vNumsCnt(8'001);
    for(int i = 0; i < N; i++){
        int x;
        std::cin >> x;
        sum += x;
        vNums[i] = x;
        vNumsCnt[4000 + x]++;
    }

    for(int i = 0; i < 8'001; i++){
        if(vNumsCnt[i] > maxCnt){
            maxCnt = vNumsCnt[i];
            maxIdx = i;
        }
    }

    for(int i = maxIdx+1; i < 8'001; i++){
        if(vNumsCnt[i] == maxCnt){
            maxIdx = i;
            break;
        }
    }

    std::sort(vNums.begin(), vNums.end());

    int a = std::round(sum/N);
    int b = vNums[(N-1)/2];
    int c = maxIdx - 4000;
    int d = vNums[N-1] - vNums[0];

    std::cout << a << "\n";
    std::cout << b << "\n";
    std::cout << c << "\n";
    std::cout << d << "\n";

    return 0;
}