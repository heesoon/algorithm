#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MIN = 2'000'000'000;
std::vector<int> v;
std::vector<int> answer(2, 0);

void solution(int n) {
    int start = 0;
    int end = n-1;

    std::sort(v.begin(), v.end(), std::less<int>());
    
    while(start < end){
        if(MIN > abs(v[start] + v[end])){
            MIN = abs(v[start] + v[end]);
            answer[0] = v[start];
            answer[1] = v[end];
        }

        if(v[start] + v[end] > 0){
            end--;
        }
        else if(v[start] + v[end] < 0){
            start++;
        }
        else{
            break;
        }
    }
}

int main(){   
    int n;
    
    std::cin >> n;
    v.assign(n, 0);

    for(int i = 0; i < n; i++){
        std::cin >> v[i];
    }

    solution(n);

    for(const int x : answer){
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}