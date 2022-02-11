#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++){
        int x1, y1, r1, x2, y2, r2;
        std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        double d = std::sqrt(std::pow((x1-x2), 2) + std::pow((y1-y2), 2));
        if(r1+r2 < d){
            std::cout << "0\n";
        }
        else if(r1+r2 == d){
            std::cout << "1\n";
        }        
        else if(std::abs(r1-r2) > d){
            std::cout << "0\n";
        }
        else if(std::abs(r1-r2) == d){
            std::cout << "1\n";
        }
        else if(d == 0 && r1 == r2){
            std::cout << "-1\n";
        }
        else{
            std::cout << "2\n";
        }    
    }

    return 0;
}