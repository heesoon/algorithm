#include <iostream>
#include <algorithm>
#include <limits>

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int a, b;
    while((std::cin >> a >> b).eof() == false){
        std::cout << a+b << "\n";
    }

    return 0;
}