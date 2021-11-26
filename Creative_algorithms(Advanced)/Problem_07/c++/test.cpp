#include <iostream>
#include <vector>
#include <string>

int a[30];
int cnt;

void solution(int n, int k) {
    if(n == 0){
        for(int i = 0; i < cnt; i++){
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
        return;
    }

    for(int i = std::min(n, k); i >= 1; i--){
        a[cnt++] = i;
        solution(n-i, i);
        cnt--;
    }
}

void tc1(){
    int n = 5;
    solution(n, n);
}

int main(){
    tc1();
    return 0;
}