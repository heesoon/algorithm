#include <iostream>

int main(){
    double a, b;
    std::cin >> a >> b;
    std::cout.precision(12);
    std::cout << std::fixed;
    std::cout << a/b << "\n";
    return 0;
}

// https://st-lab.tistory.com/212