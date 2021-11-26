#include <iostream>
#include <vector>
#include <string>

std::string solution(int idx, int a, int l, const std::string &str) {
    std::string out = "";

    if(str[idx] == '0' || str[idx] == '1'){
        for(int i = 0; i < l; i++){
            out += str[idx];
        }

        return out;
    }

    return out += solution(idx+1, a, l/2, str) + solution(idx+2, a+l/2, l/2, str);
}

void tc1(){
    int l = 4;
    std::string str = "-1-01";

    if("1101" == solution(0, 0, l, str)){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
    int l = 8;
    std::string str = "1";

    if("11111111" == solution(0, 0, l, str)){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

int main(){
    tc1();
    tc2();
    return 0;
}