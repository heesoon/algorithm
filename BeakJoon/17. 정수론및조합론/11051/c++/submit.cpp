#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    std::string str;
    int num = 0, sum = 0;
    bool bMinus = false;
    std::cin >> str;
    for(int i = 0; i <= str.size(); i++){
        if(str[i] == '+' || str[i] == '-' || i == str.size()){

            if(bMinus == false){
                sum += num;
                num = 0;
            }
            else{
                sum -= num;
                num = 0;
            }
            
            if(str[i] == '-'){
                bMinus = true;
            }            
        }
        else{
            num *= 10;
            num += str[i] - '0';
        }
    }

    std::cout << sum << "\n";
    return 0;
}