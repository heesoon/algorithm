#include <iostream>

int main(){
    int n, a, b;
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::cin >> n;
    for(int i = 0; i < n; i++){
        std::cin >> a >> b;
        std::cout << a+b << "\n";
    }
    return 0;
}