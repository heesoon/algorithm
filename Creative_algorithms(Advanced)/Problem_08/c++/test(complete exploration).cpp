#include <iostream>
#include <vector>
int minCnt = -1;

void solution(int cnt, int start, int end, const std::vector<int> &abilities) {
    if(start == end){
        if(minCnt == -1){
            minCnt = cnt;
        }
        else{
            if(minCnt > cnt){
                minCnt = cnt;
            }
        }

        return;
    }
    else if(start < end){
        for(const auto &a : abilities){
            solution(cnt+1, start + a, end, abilities);
        }
    }
}

void tc1(){
    int start = 1;
    int end = 15;
    std::vector<int> abilities{2, 5, 7};

    solution(0, start, end, abilities);

    std::cout << minCnt << std::endl;
}

int main(){
    tc1();
    return 0;
}