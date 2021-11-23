#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int INF = 2'000'000'000;
std::vector<int> v;
std::vector<int> answer(2, 0);

#if 0
void solution(int n) {
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(INF > abs(v[i] + v[j])){
                INF = v[i] + v[j];
                if(v[i] > v[j]){
                    answer[0] = v[j];
                    answer[1] = v[i];
                }
                else{
                    answer[0] = v[i];
                    answer[1] = v[j];
                }
            }
        }
    }
}
#endif

void solution(int n) {
    int start = 0;
    int end = n-1;

    std::sort(v.begin(), v.end(), std::less<int>());
    
    for(const auto x : v)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    
    INF = abs(v[start] + v[end]);
    while(start < end){

        std::cout << start << " , " << end << " , " << INF << std::endl;
        while(start < end && INF > abs(v[start] + v[end])){
            start++;
        }

        std::cout << "start : " << start << std::endl;
        while(start < end && INF > abs(v[start] + v[end])){
            end--;
        }

        std::cout << "end : " << end << std::endl;
        if(INF > abs(v[start] + v[end])){
            INF = abs(v[start] + v[end]);
            start++;
        }
        else{
            answer[0] = v[start];
            answer[1] = v[end];
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