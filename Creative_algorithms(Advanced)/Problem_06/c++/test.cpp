#include <iostream>
#include <vector>
#include <string>

bool isSame(int a, int l, const std::string &str){
    for(int i = a; i < a+l; i++){
        if(str[a] != str[i]){
            return false;
        }
    }

    return true;
}

std::string solution(int a, int l, const std::string &str) {
    std::string out = "";

    if(l == 1 || isSame(a, l, str)){
        out += str[a];
        return out;
    }
    
    return '-' + solution(a, l/2, str) + solution(a+l/2, l/2, str);
}

void tc1(){
    int l = 4;
    std::string str = "0000";

    if("0" == solution(0, l, str)){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
    int l = 4;
    std::string str = "1101";

    if("-1-01" == solution(0, l, str)){
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