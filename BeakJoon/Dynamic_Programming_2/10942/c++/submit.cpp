#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

std::vector<int> numbers;
//std::vector<std::vector<int>> questions;
std::vector<std::vector<int>> DT;

void solve(int n){
    for(int i = 0; i < n; i++){
        DT[i][i] = 1;
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < n-i; j++){
            int k = i+j;
            if(i == 1) DT[j][k] = numbers[j] == numbers[k];
            else DT[j][k] = ((numbers[j] == numbers[k]) && DT[j+1][k-1]) ? 1 : 0; 
        }
    }
}

int main(){
    int n; // 2001
    int m; // 1,000,001
    int a, b;

    std::cin >> n;

    numbers.assign(n, 0);
    //questions.assign(n, std::vector<int>(2, 0));
    DT.assign(n, std::vector<int>(n, 0));

    for(int i = 0; i < n; i++){
        std::cin >> numbers[i];
    }

    solve(n);

#if 0
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cout << DT[i][j] << " ";
        }
        std::cout << "\n";
    }
#endif

    std::cin >> m;
    for(int i = 0; i < m; i++){
        std::cin >> a >> b;
        std::cout << DT[a-1][b-1] << "\n";
    }

    return 0;
}