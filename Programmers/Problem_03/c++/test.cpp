#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    std::unordered_map<std::string, int> map;

    for(const auto& clothe_arr : clothes){
        std::string key = clothe_arr[1];
        map[key] += 1;
    }

    for(const auto& pair : map){
        answer = answer * (pair.second + 1);
    }

    return answer - 1;
}

void tc1(){
    std::vector<std::vector<std::string>> clothes = {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};
    if(solution(clothes) == 5){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
    std::vector<std::vector<std::string>> clothes = {{"crowmask", "face"}, {"bluesunglasses", "face"}, {"smoky_makeup", "face"}};
    if(solution(clothes) == 3){
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