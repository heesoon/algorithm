#include <iostream>
#include <vector>
#include <algorithm>

const int MAX = 1000 + 1;
const int INF = 1'000'000'000;
std::vector<int> DT(MAX, INF);

int solution(int start, int end, const std::vector<int> &abilities) {
    DT[start] = 0;

    for(int i = start+1; i <= end; i++){
        int temp = INF;
        for(const auto &a : abilities){
            if(i-a >= start){
                temp = std::min(temp, DT[i-a]+1);
            }
        }

        DT[i] = temp;
    }

    return DT[end] != INF ? DT[end] : -1;
}

void tc1(){
    int start = 1;
    int end = 15;
    std::vector<int> abilities{2, 5, 7};

    if(2 == solution(start, end, abilities)){
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