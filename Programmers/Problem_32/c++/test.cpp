#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long s = 1;
    long long e = *max_element(times.begin(), times.end()) * (long long)n;

    while(s <= e){
        long long cnt = 0;
        long long mid = (s + e)/2;

        for(const auto &t : times){
            cnt += mid/t;
        }

        if(cnt < n){
            s = mid + 1;
        }
        else{
            answer = mid;
            e = mid - 1;
        }
    }

    return answer;
}

void tc1(){
	int n = 6;
	std::vector<int> times = {7, 10};

    long long answer = solution(n, times);
    if(answer == 28){
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