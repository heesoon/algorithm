#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    std::unordered_map<std::string, int> map;
    for(auto book : phone_book){
        for(std::string::size_type i = 1; i <= book.size(); i++){
            std::string idxString = book.substr(0, i);
            if(map.find(idxString) != map.end()){
                return false;
            }
        }
        map[book] = 1;
    }

    return answer;
}

void tc1(){
    std::vector<std::string> phone_book = {"119", "97674223", "1195524421"};
    if(solution(phone_book) == false){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc2(){
    std::vector<std::string> phone_book = {"123","456","789"};
    if(solution(phone_book) == true){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

void tc3(){
    std::vector<std::string> phone_book = {"12","123","1235","567","88"};
    if(solution(phone_book) == false){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

int main(){
    tc1();
    tc2();
    tc3();
    return 0;
}